//
//  PokerFunctions.cpp
//  Poker
//
//  Created by Anna Thomas on 9/1/21.
// Ryan Brumfield
// Ryan Jensen

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Card {
	std::string suit;
	std::string color;
	int rank;
};

// Function which returns a new deck of cards.
std::vector<Card> generateDeck();

// returns a string if Ace, Jack, Queen, King, otherwise returns card rank as
// string.
std::string getCardTextFromRank(Card &c);

// shufflesanexistingDeck
void shuffleDeck(std::vector<Card> &myDeck);
void printshuffledDeck(std::vector<Card> &someDeck);
void printHand(std::vector<Card> &someDeck);
void printHandPoker(std::vector<Card> &someHand);
std::vector<Card> makeMyHand(std::vector<Card> &myDeck);
bool comp(const Card &c1, const Card &c2);
bool isFlush(std::vector<Card> &someDeck);
bool isStraight(std::vector<Card> &someDeck);
bool isStraightFlush(std::vector<Card> &someDeck);
bool isRankRoyal(std::vector<Card> &someDeck);
bool isRoyalFlush(std::vector<Card> &someDeck);
bool isFullHouse(std::vector<Card> &someDeck);

std::string getCardTextFromRank(Card &c) {	//& PULLS c
	std::string cardText;
	if (c.rank == 1) {
		cardText = "A";
	} else if (c.rank == 11) {
		cardText = "J";
	} else if (c.rank == 12) {
		cardText = "Q";
	} else if (c.rank == 13) {
		cardText = "K";
	} else {
		cardText = std::to_string(c.rank);
	}
	// ace can be high or low for the assigment
	return cardText;
}

std::vector<Card> generateDeck() {
	std::string suits[] = {"clubs", "diamonds", "hearts", "spades"};
	std::vector<Card> deck;

	for (std::string suit :
			 suits) {	 // assigns card values to each string value in suits
		for (int i = 1; i < 14; i++) {
			Card c;
			c.rank = i;
			c.suit = suit;
			if (suit == "diamonds" || suit == "hearts") {
				c.color = "red";
			} else {
				c.color = "black";
			}
			deck.push_back(c);
		}
	}
	return deck;
}

void printshuffledDeck(std::vector<Card> &someDeck) {
	std::cout << "Your shuffled deck's card order is:\n";
	for (Card c : someDeck) {
		std::cout << getCardTextFromRank(c) << " of " << c.suit << "; " << c.color
							<< ".\n";
	}
}

void printHand(std::vector<Card> &someDeck) {
	std::cout << "Your hand is: \n";
	for (Card c : someDeck) {
		std::cout << getCardTextFromRank(c) << " of " << c.suit << "; " << c.color
							<< ".\n";
	}
}

void printHandPoker(std::vector<Card> &someHand) {
	if (isFlush(someHand) == true) {
		std::cout << "Your hand is a flush.\n";
	}
	if (isStraight(someHand) == true) {
		std::cout << "Your hand is a straight.\n";
	}
	if (isStraightFlush(someHand) == true) {
		std::cout << "Your hand is a straight flush.\n";
	}
	if (isRoyalFlush(someHand) == true) {
		std::cout << "Your hand is a royal flush. Wow!\n";
	}
}

void shuffleDeck(std::vector<Card> &myDeck) {
	for (int a = myDeck.size() - 1; a >= 0; a--) {
		// work our way down from the last index to index 0

		int b = rand() % myDeck.size();
		// give me a random number that returns a remainder when it is divided by
		// the size of the deck. that remainder will be b need to subtract one
		// because b will be used to index the vector<Card> myDeck
		// randNum_in_a_range = rand() % (b-a) + a //where b is the upper limit,
		// which is not included, a is the lower limit, and IS included

		std::swap(myDeck[a], myDeck[b]);
	}
}

std::vector<Card> makeMyHand(std::vector<Card> &myDeck) {
	std::vector<Card> myHand(5);

	for (int a = 0; a < 5; a++) {
		myHand[a].suit =
			myDeck[a].suit;	 // can't just do myHand[a] = myDeck[a]; //why? //must
											 // reassign each variable of this vector of struct (type)
											 // Card with its corresponding field
		myHand[a].rank = myDeck[a].rank;
		myHand[a].color = myDeck[a].color;

		// but shouldn't myHand only end up being a vector of size 5? why does my
		// thing keep iterating - must established or else behavior is undefined
	}
	std::sort(myHand.begin(), myHand.end(), comp);
	return myHand;
}

bool isFlush(std::vector<Card> &someDeck) {
	std::vector<Card> myHand = makeMyHand(someDeck);

	for (int a = 0; a < myHand.size() - 1; a++) {
		if (myHand[a].suit != myHand[a + 1].suit) {
			return false;
		}
	}
	return true;
}

// isStraight: are all 5 cards in numerical order (note this is a little tricky
// because the hand is unsorted! -- made a function to sort the hand, call it
// with makeMyHand(someDeck))
bool comp(
	const Card &c1,
	const Card &c2) {	 // placement of const can be before or after the type //
										 // return whether c1 < c2

	if (c1.rank < c2.rank) {	//< is an operator that can be used with ints, so
														// translate the card to an int it can understand
		return true;
	}
	return false;
}

bool isStraight(std::vector<Card> &someDeck) {
	std::vector<Card> myHand = makeMyHand(someDeck);

	for (int a = 0; a < myHand.size() - 1; a++) {
		if (myHand[a].rank != myHand[a + 1].rank - 1) {
			return false;
		}
	}
	return true;
}

// isStraightFlush: is this hand both a straight and a flush?

bool isStraightFlush(std::vector<Card> &someDeck) {
	std::vector<Card> myHand = makeMyHand(someDeck);

	if (isStraight(myHand) == true && isFlush(myHand) == true) {
		return true;
	}
	return false;
}

bool isRankRoyal(std::vector<Card> &someDeck) {
	std::vector<Card> myHand = makeMyHand(someDeck);

	for (int a = 0; a < 5; a++) {
		if (
			myHand[a].rank >= 10 ||
			myHand[a].rank ==
				1) {	// aces can be high or low, so it should have the same true-ness
							// for this function so that it can be accounted for in the
							// following functions that use isRankGreater
			return true;
		}
	}
	return false;
}

// isRoyalFlush: is this hand a straight flush whose low card is a ten?

bool isRoyalFlush(std::vector<Card> &someDeck) {
	std::vector<Card> myHand = makeMyHand(someDeck);

	if (isStraightFlush(myHand) == true && isRankRoyal(myHand) == true) {
		return true;
	}
	return false;
}

// isFullHouse: are there 3 of one rank, and 2 of another (for example: 3 aces
// and 2 fives) aces can be high or low -- accounted for in function isGreater

bool isFullHouse(std::vector<Card> &someDeck) {
	std::vector<Card> myHand = makeMyHand(someDeck);

	// 1 5 1 5 1
	// 5 1 5 1 5
	// two cases bc they will be sorted:
	// 1 1 1 5 5
	// 1 1 5 5 5
	if (
		myHand[0].rank == myHand[1].rank && myHand[1].rank == myHand[2].rank &&
		myHand[3].rank == myHand[4].rank) {
		return true;
	}

	if (
		myHand[0].rank == myHand[1].rank && myHand[2].rank == myHand[3].rank &&
		myHand[3].rank == myHand[4].rank) {
		return true;
	}
	return false;
}
//
// Ask Yang about overload operators, class, diff between class and just having
// struct freefloating in a .h file, benefits
// get into data structures!!!!!!!
// std::sort(myHand.begin(), myHand.end());
// to use sort, add an overload operator in the Class that contains the struct
// Card
//      std::sort(cars.begin(), cars.end()); // requires an overloaded operator<
//
//      for (const auto& car : cars ) //establish a const "auto", use &car
//        std::cout << car << '\n'; // requires an overloaded operator<<

//
//  main.cpp
//  Poker
//
//  Created by Anna Thomas on 9/1/21.
//

int main() {
	std::vector<Card> myDeck = generateDeck();	// makes a deck named "myDeck"
	shuffleDeck(myDeck);	// shuffles said deck
	printshuffledDeck(myDeck);	// prints said deck
	std::vector<Card> myHand = makeMyHand(
		myDeck);	// turns said deck into a hand (vector) of Cards, size 5
	printHand(myHand);	// prints new "deck" (now colloquially a hand)
	// printHandPoker(myHand);

	int x = 0;
	int y = 0;
	int z = 0;
	int z2 = 0;
	int z3 = 0;

	for (int a = 0; a < 1000000; a++) {
		shuffleDeck(myDeck);
		myHand = makeMyHand(myDeck);

		if (isFlush(myHand) == true) {
			x++;
		}
		if (isStraight(myHand) == true) {
			y++;
		}
		if (isStraightFlush(myHand) == true) {
			z++;
		}
		if (isRoyalFlush(myHand) == true) {
			z2++;
		}
		if (isFullHouse(myHand) == true) {
			z3++;
		}

		// int cz2ount
	}
	// shuffleDeck(myDeck);
	// printshuffledDeck(myDeck);
	// std::vector<Card> myHand2 = makeMyHand(myDeck);
	// printHand(myHand2);
	// printHandPoker(myHand2);

	return 0;
}

// After each shuffle, check whether the hand is one of the hands you test for
// above and keep track of the total numbers of flushes, straights, royal
// flushes, etc, you see.
// Print out what fraction of hands are one of the above. You probably will not
// see a royal flush until you examine 100k to 1 milion hands! At the top of
// your code (in comments), record the percentage you see each type of hand.

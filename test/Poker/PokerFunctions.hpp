//
//  PokerFunctions.hpp
//  Poker
//
//  Created by Anna Thomas on 9/1/21.
//

#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#ifndef PokerFunctions_hpp
#define PokerFunctions_hpp


struct Card {
    std::string suit;
    std::string color;
    int rank;
};

// Function which returns a new deck of cards.
std::vector<Card> generateDeck();

// returns a string if Ace, Jack, Queen, King, otherwise returns card rank as string.
std::string getCardTextFromRank(Card &c);

//shufflesanexistingDeck
void shuffleDeck (std::vector<Card> & myDeck);
void printshuffledDeck (std::vector<Card> &someDeck);
void printHand(std::vector<Card> &someDeck);
void printHandPoker(std::vector<Card> &someHand);
std::vector<Card> makeMyHand (std::vector<Card> &myDeck);
bool comp(const Card &c1, const Card &c2);
bool isFlush (std::vector<Card> someDeck);
bool isStraight (std::vector<Card> someDeck);
bool isStraightFlush (std::vector<Card> someDeck);
bool isRankRoyal (std::vector<Card> someDeck);
bool isRoyalFlush (std::vector<Card> someDeck);
bool isFullHouse (std::vector<Card> someDeck);

#endif /* PokerFunctions_hpp */



#include <cmath>
#include <iostream>
#include <string>

// NOT using namespace std;

// struct Suits {
// 	int club = 1;	 // can I do int club = 1 ? and then later tell it to output
// 								 // "club" for when Card.Suits.1 <--- is 1?
// 	int spade = 2;
// 	int diamond = 3;
// 	int heart = 4;
// };
struct Card {
	int rank;	 // what number value does it have from 1-13
	// int suit; // OKAY: only store values 1-4 in here.
	// Suits theSuit;	// Card.Suits.club == "club" or, Card.Suits.1 = club;
	int theSuit;
	// int club = 1; //can I do int club = 1 ? and then later tell it to output
	// "club" for when Card.Suits.1 <--- is 1? int spade = 2; int diamond = 3; int
	// heart = 4;
};

// Takes some card, outputs string for c’s suit.
std::string getSuitStr(Card c) {
	std::string actualSuit;
	if (c.theSuit == 1) {
		actualSuit = "Club";
	}
	// ...
	// TODO
	return actualSuit;
}

int main() {
	// Card c1, c2;

	// // c1 as Spades 12?
	// c1.rank = 12;
	// c1.theSuit = 2;

	// // test if c2 is diamond?
	// if (c2.theSuit == 3) {
	// 	// c2 is diamond
	// }

	// // are c1 and c2 the same suit?
	// if (c1.theSuit == c2.theSuit) {
	// }

	// // 1, 2, 3, 4, ..., 12
	// // => "January", "February", ...
	// if (c1.theSuit == 1) {
	// 	std::cout << "Clubs";
	// }

	// // etc...
	// std::cout << getSuitStr(c1);

	return 0;
}

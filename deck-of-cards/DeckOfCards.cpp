//
//  DeckOfCards.cpp
//  DeckOfCards
//
//  Created by Anna Thomas on 8/31/21.
//

#include "DeckOfCards.hpp"

// NOT using namespace std:: so make sure it's added to all the strings,
// vectors, etc.

// we ONLY want to make a deck of cards. only one function needed, and that is
// to assemble the deck

std::vector<Card> makeDeck() {
	std::vector<Card> finishedDeck;
	int count = 0;	// start with an empty deck

	while (count <= 52) {
		for (int a = 0; a < 13; a++) {
			Card allclubs;
			allclubs.rank = a + 1;
			allclubs.theSuit.club = 1;
			finishedDeck.push_back(allclubs);
		}
		for (int a = 13; a < 26;
				 a++) {	 // start at index 13, since indices 0-12 are full of allclubs
			Card allspades;
			allspades.rank = a + 1;
			allspades.theSuit.spade = 2;
			finishedDeck.push_back(allspades);
		}
		for (int a = 26; a < 39;
				 a++) {	 // start at index 26, 13-25 are now full of allspades
			Card alldiamonds;
			alldiamonds.rank = a + 1;
			alldiamonds.theSuit.diamond = 3;
			finishedDeck.push_back(alldiamonds);
		}
		for (int a = 39; a <= 52;
				 a++) {	 // start at index 39, 26-38 are now full of alldiamonds
			Card allhearts;
			allhearts.rank = a + 1;
			allhearts.theSuit.heart = 4;
			finishedDeck.push_back(allhearts);
			// now slots 39-52 are full of allhearts
			// nice
		}
	}
	return finishedDeck;
}
// for loop structure  for( initialization; condition; increment/updation){ do
// this } for each loop structure  for( variable : someVector) { do this }

// variable type + variable_name.field

//
//  DeckOfCards.hpp
//  DeckOfCards
//
//  Created by Anna Thomas on 8/31/21.
//

#ifndef DeckOfCards_hpp
#define DeckOfCards_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//NOT using namespace std;

struct Suits {
    int club = 1; //can I do int club = 1 ? and then later tell it to output "club" for when Card.Suits.1 <--- is 1?
    int spade = 2;
    int diamond = 3;
    int heart = 4;
};
struct Card {
    int rank; //what number value does it have from 1-13
    Suits theSuit; //Card.Suits.club == "club" or, Card.Suits.1 = club;
};

//always remember semi-colon after a struct declaration

std::vector<Card> makeDeck();

//executes making a deck when makeDeck() is called (not a member function?)


#endif /* DeckOfCards_hpp */

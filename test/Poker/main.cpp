//
//  main.cpp
//  Poker
//
//  Created by Anna Thomas on 9/1/21.
//

#include <stdio.h>
#include "PokerFunctions.hpp"

int main() {
    
    std::vector<Card> myDeck = generateDeck(); //makes a deck named "myDeck"
    shuffleDeck(myDeck); //shuffles said deck
    printshuffledDeck(myDeck); //prints said deck
    std::vector<Card> myHand = makeMyHand(myDeck); //turns said deck into a hand (vector) of Cards, size 5
    printHand(myHand); //prints new "deck" (now colloquially a hand)
    printHandPoker(myHand);
    shuffleDeck(myDeck);
    printshuffledDeck(myDeck);
    std::vector<Card> myHand2 = makeMyHand(myDeck);
    printHand(myHand2);
    printHandPoker(myHand2);
    
    return 0;
}

//
// Created by minau on 10/31/2022.
//

#ifndef SFML_PROJECT_DECK_H
#define SFML_PROJECT_DECK_H
#include "Card.h"
#include <iostream>

class Deck :public Card {
private:
    int cardIndex = 0;
    int DECK_SIZE = 52;
   // CardCard deck[52]; for array
    bool empty();
    std::vector<Card> deck;
public:
    void shuffle();
    void init();
    Deck();
    void printDeck();
    Card dealCard(Deck d);
    Card getCardAt(int index);
    Deck(const Deck& d);
};


#endif //SFML_PROJECT_DECK_H

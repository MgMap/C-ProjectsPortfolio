//
// Created by minau on 11/1/2022.
//

#ifndef SFML_PROJECT_CARDHAND_H
#define SFML_PROJECT_CARDHAND_H
#include "Deck.h"
#include <algorithm>
class CardHand :public Deck{
private:
     int handSize = 5;
    std::vector<Card> drawCard;
public:
    std::vector<Card> getDrawCard();
    void addCard(Deck d);
    void printCardHand();
    void sort();
};


#endif //SFML_PROJECT_CARDHAND_H

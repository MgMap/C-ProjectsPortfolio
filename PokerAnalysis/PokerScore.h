//
// Created by minau on 11/2/2022.
//


#ifndef SFML_PROJECT_POKERSCORE_H
#define SFML_PROJECT_POKERSCORE_H

#include <vector>


enum ScoresEnum{

    ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

    STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

    FOUR_OF_A_KIND, //four cards of the same ranking

    FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

    FLUSH, //five cards of the same suit

    STRAIGHT, //five cards in consecutive ranking

    THREE_OK_A_KIND, //three cards of the same rank

    TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

    ONE_PAIR, //two cards of the same rank

    HIGH_CARD //highest card in the player’s hand

};

class PokerScore  {
private:

    int scoreCount=0;
public:
    std::vector<ScoresEnum> scoresEnum;

    void pushBack(ScoresEnum scoreEnum);
    void operator+=(const ScoresEnum& scoreEnum);
    PokerScore& operator=(const PokerScore& pokerscore);
    int size();
    ScoresEnum& operator[](unsigned int index);
    PokerScore();
    std::vector<ScoresEnum> GetScore();
};



#endif //SFML_PROJECT_POKERSCORE_H


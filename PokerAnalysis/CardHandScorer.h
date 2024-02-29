//
// Created by minau on 11/2/2022.
//
/*
 * Next, create another class, CardHandScorer that is used to analyze a players hand
 * and determine a score for that hand. Because we are going to create a Poker game we will focus on making a scorer for Poker only,
 * though in the future, we will add function for other card games such as Blackjack. The CardHandScorer class should have the following:
a static function that takes a CardHand object as an argument. The purpose of this static function is to return the score for the Poker hand.
 This score will be stored in a PokerScore object that is mention in the next section.
The function should analyze the CardHand and add all possible scores to the PokerScore object in which it will then return this object.
 */
#ifndef SFML_PROJECT_CARDHANDSCORER_H
#define SFML_PROJECT_CARDHANDSCORER_H

#include "CardHand.h"
#include <algorithm>
#include <vector>
#include "PokerScore.h"
class CardHandScorer : public CardHand {

public:
    static PokerScore scorePokerHand1(CardHand ch);
    static bool isRoyalFlush(CardHand ch);
    static bool isStraightFlush(CardHand ch);
    static bool isFourOfAKind(CardHand ch);
     static bool isFullHouse(CardHand ch);
     static bool isFlush(CardHand ch);
     static bool isStraight(CardHand ch);
     static bool isThreeOfAKind(CardHand ch);
     static bool isTwoPair(CardHand ch);
     static bool isOnePair(CardHand ch);
    static bool isHighCard(CardHand ch);
};


#endif //SFML_PROJECT_CARDHANDSCORER_H

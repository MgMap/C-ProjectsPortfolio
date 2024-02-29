//
// Created by minau on 11/14/2022.
//

#ifndef SFML_PROJECT_DRAW_CARDHAND_H
#define SFML_PROJECT_DRAW_CARDHAND_H
#include "Card.h"
#include "draw_card.h"
#include "test.h"

class draw_cardHand: public draw_card {
private:
    const int CARD_COUNT = 5;
    sf::Text scoreType, percentage;

    //append cards to each individual vectors
    void RoyalFlushCards();
    void StraightFlushCards();
    void FourOfAKindCards();
    void FullHouseCards();
    void FlushCards();
    void StraightCards();
    void ThreeOfAKindCards();
    void TwoPairsCards();
    void OnePairCards();
    void HighCards();

    std::vector<double> scoresPercentage;
public:
    //create sample cardHand types and set the positions of five cards relative to one another
    std::vector<draw_card> royal_flush;
    std::vector<draw_card> straight_flush;
    std::vector<draw_card> four_of_a_kind;
    std::vector<draw_card> full_house;
    std::vector<draw_card> flush;
    std::vector<draw_card> straight;
    std::vector<draw_card> three_of_a_kind;
    std::vector<draw_card> two_pair;
    std::vector<draw_card> one_pair;
    std::vector<draw_card> high_cards;

    draw_cardHand();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void appendCards();
    void arrangeCards(); //create cardHand objects
    void setCardPositions(std::vector<draw_card>& cardHand, sf::Vector2f positionOfHand) const;

    //string output for score type and odds of getting the score
    //try using string concat for
    const unsigned FONT_SIZE = 12;
    sf::Text royalFlushText, straightFlushText, fourOfAKindText, fullHouseText,
            flushText, straightText, threeOfAKindText, twoPairText, onePairText, highCardText;
    void textDisplayForScores();
};
#endif //SFML_PROJECT_DRAW_CARDHAND_H

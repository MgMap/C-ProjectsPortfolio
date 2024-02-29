//
// Created by minau on 11/14/2022.
//

#include "draw_cardHand.h"


draw_cardHand::draw_cardHand() {
    //default constructor
    appendCards();
    arrangeCards();
    scoresPercentage = runProgram();
    textDisplayForScores();
}

void draw_cardHand::appendCards() {
    RoyalFlushCards();
    StraightFlushCards();
    FourOfAKindCards();
    FullHouseCards();
    FlushCards();
    StraightCards();
    ThreeOfAKindCards();
    TwoPairsCards();
    OnePairCards();
    HighCards();

}

void draw_cardHand::arrangeCards() {
    const int LEFT_ALIGN = 30;
    const int TOP_ALIGN = 10;
    setCardPositions(royal_flush, {LEFT_ALIGN, TOP_ALIGN}); royalFlushText.setPosition({LEFT_ALIGN, 110});
    setCardPositions(straight_flush, {LEFT_ALIGN, TOP_ALIGN+140}); straightFlushText.setPosition({LEFT_ALIGN, 250});
    setCardPositions(four_of_a_kind, {LEFT_ALIGN, TOP_ALIGN+280}); fourOfAKindText.setPosition({LEFT_ALIGN, 390});
    setCardPositions(full_house, {LEFT_ALIGN, TOP_ALIGN+420}); fullHouseText.setPosition({LEFT_ALIGN, 530});
    setCardPositions(flush, {LEFT_ALIGN, TOP_ALIGN+560}); flushText.setPosition({LEFT_ALIGN, 670});
    const int RIGHT_ALIGN = 550;
    setCardPositions(straight, {RIGHT_ALIGN, TOP_ALIGN}); straightText.setPosition({RIGHT_ALIGN, 110});
    setCardPositions(three_of_a_kind, {RIGHT_ALIGN, TOP_ALIGN+140}); threeOfAKindText.setPosition({RIGHT_ALIGN, 250});
    setCardPositions(two_pair, {RIGHT_ALIGN, TOP_ALIGN+280}); twoPairText.setPosition({RIGHT_ALIGN, 390});
    setCardPositions(one_pair, {RIGHT_ALIGN, TOP_ALIGN+420}); onePairText.setPosition({RIGHT_ALIGN, 530});
    setCardPositions(high_cards, {RIGHT_ALIGN, TOP_ALIGN+560}); highCardText.setPosition({RIGHT_ALIGN, 670});
}

void draw_cardHand::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i=0; i<5; i++) {
        //DRAW CARDS ON THE LEFT
        window.draw(royal_flush[i]); window.draw(royalFlushText);
        window.draw(straight_flush[i]); window.draw(straightFlushText);
        window.draw(four_of_a_kind[i]); window.draw(fourOfAKindText);
        window.draw(full_house[i]); window.draw(fullHouseText);
        window.draw(flush[i]); window.draw(flushText);
        //DRAW CARDS ON THE RIGHT
        window.draw(straight[i]); window.draw(straightText);
        window.draw(three_of_a_kind[i]); window.draw(threeOfAKindText);
        window.draw(two_pair[i]); window.draw(twoPairText);
        window.draw(one_pair[i]); window.draw(onePairText);
        window.draw(high_cards[i]); window.draw(highCardText);
    }
}

void draw_cardHand::RoyalFlushCards() {

    draw_card card1(DIAMONDS,ACE), card2(DIAMONDS,TEN), card3(DIAMONDS,JACK), card4(DIAMONDS,KING), card5(DIAMONDS,QUEEN);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        royal_flush.push_back(cards[i]);
    }
}

void draw_cardHand::StraightFlushCards() {
    draw_card card1(HEARTS,THREE), card2(HEARTS,FOUR), card3(HEARTS,FIVE), card4(HEARTS,SIX), card5(HEARTS,SEVEN);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        straight_flush.push_back(cards[i]);
    }
}


void draw_cardHand::FourOfAKindCards() {
    draw_card card1(DIAMONDS,TEN), card2(HEARTS,TEN), card3(SPADES,TEN), card4(CLUBS,TEN), card5(DIAMONDS,QUEEN);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        four_of_a_kind.push_back(cards[i]);
    }
}


void draw_cardHand::FullHouseCards() {
    draw_card card1(DIAMONDS,TEN), card2(HEARTS,TEN), card3(SPADES,TEN), card4(CLUBS,QUEEN), card5(DIAMONDS,QUEEN);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        full_house.push_back(cards[i]);
    }
}

void draw_cardHand::FlushCards() {
    draw_card card1(CLUBS,THREE), card2(CLUBS,FIVE), card3(CLUBS,SIX), card4(CLUBS,EIGHT), card5(DIAMONDS,QUEEN);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        flush.push_back(cards[i]);
    }
}

void draw_cardHand::StraightCards() {
    draw_card card1(DIAMONDS,TWO), card2(HEARTS,THREE), card3(SPADES,FOUR), card4(CLUBS,FIVE), card5(DIAMONDS,SIX);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        straight.push_back(cards[i]);
    }
}

void draw_cardHand::ThreeOfAKindCards() {
    draw_card card1(DIAMONDS,FOUR), card2(HEARTS,FOUR), card3(SPADES,FOUR), card4(CLUBS,FOUR), card5(DIAMONDS,SIX);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        three_of_a_kind.push_back(cards[i]);
    }
}

void draw_cardHand::TwoPairsCards() {
    draw_card card1(DIAMONDS,FIVE), card2(HEARTS,FIVE), card3(SPADES,JACK), card4(CLUBS,JACK), card5(HEARTS,KING);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        two_pair.push_back(cards[i]);
    }
}

void draw_cardHand::OnePairCards() {
    draw_card card1(DIAMONDS,NINE), card2(HEARTS,NINE), card3(SPADES,JACK), card4(CLUBS,KING), card5(HEARTS,QUEEN);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        one_pair.push_back(cards[i]);
    }
}

void draw_cardHand::HighCards() {
    draw_card card1(DIAMONDS,TWO), card2(HEARTS,FIVE), card3(SPADES,TEN), card4(CLUBS,JACK), card5(HEARTS,KING);
    draw_card cards[] = {card1, card2, card3,card4,card5};
    for(int i =0; i < 5; i ++)
    {
        high_cards.push_back(cards[i]);
    }
}
void draw_cardHand::setCardPositions(std::vector<draw_card>& cardHand, sf::Vector2f positionOfHand) const {
    //set position of cards
    float x = positionOfHand.x;
    for(int i=0; i<CARD_COUNT; i++) {
        //change the distance between each cards of the hand
        cardHand[i].setPosition({x, positionOfHand.y});
        x += 80;
    }
}

void draw_cardHand::textDisplayForScores() {

    if(!font.loadFromFile("PokerAnalysis/font/OpenSans-Bold.ttf"))
        exit(10);


    royalFlushText.setFont(font), straightFlushText.setFont(font), fourOfAKindText.setFont(font), fullHouseText.setFont(font),
            flushText.setFont(font), straightText.setFont(font), threeOfAKindText.setFont(font), twoPairText.setFont(font), onePairText.setFont(font), highCardText.setFont(font);

    royalFlushText.setCharacterSize(FONT_SIZE), straightFlushText.setCharacterSize(FONT_SIZE), fourOfAKindText.setCharacterSize(FONT_SIZE),
            fullHouseText.setCharacterSize(FONT_SIZE), flushText.setCharacterSize(FONT_SIZE), straightText.setCharacterSize(FONT_SIZE),
            threeOfAKindText.setCharacterSize(FONT_SIZE), twoPairText.setCharacterSize(FONT_SIZE), onePairText.setCharacterSize(FONT_SIZE), highCardText.setCharacterSize(FONT_SIZE);

    royalFlushText.setFillColor(sf::Color::Black);straightFlushText.setFillColor(sf::Color::Black), fourOfAKindText.setFillColor(sf::Color::Black),
            fullHouseText.setFillColor(sf::Color::Black), flushText.setFillColor(sf::Color::Black), straightText.setFillColor(sf::Color::Black),
            threeOfAKindText.setFillColor(sf::Color::Black), twoPairText.setFillColor(sf::Color::Black), onePairText.setFillColor(sf::Color::Black), highCardText.setFillColor(sf::Color::Black);


    const std::string text0 = "ROYAL FLUSH: " + std::to_string(scoresPercentage[0]) + "%";
    const std::string text1 = "STRAIGHT FLUSH: " + std::to_string(scoresPercentage[1]) + "%";
    const std::string text2 = "FOUR OF A KIND: " + std::to_string(scoresPercentage[2]) + "%";
    const std::string text3 = "FULL HOUSE: " + std::to_string(scoresPercentage[3]) + "%";
    const std::string text4 = "FLUSH: " + std::to_string(scoresPercentage[4]) + "%";
    const std::string text5 = "STRAIGHT: " + std::to_string(scoresPercentage[5]) + "%";
    const std::string text6 = "THREE OF A KIND: " + std::to_string(scoresPercentage[6]) + "%";
    const std::string text7 = "TWO PAIR: " + std::to_string(scoresPercentage[7]) + "%";
    const std::string text8 = "ONE PAIR: " + std::to_string(scoresPercentage[8]) + "%";
    const std::string text9 = "HIGH CARD: " + std::to_string(scoresPercentage[9]) + "%";

    royalFlushText.setString(text0), straightFlushText.setString(text1), fourOfAKindText.setString(text2),
            fullHouseText.setString(text3), flushText.setString(text4), straightText.setString(text5),
            threeOfAKindText.setString(text6), twoPairText.setString(text7), onePairText.setString(text8), highCardText.setString(text9);
}
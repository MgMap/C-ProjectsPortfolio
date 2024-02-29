//
// Created by minau on 10/25/2022.
//

#include "Card.h"

Card::Card() : Card(HEARTS, ACE)
{

}

Card::Card(suitEnum suit, rankEnum rank) :_suit(suit) ,_rank(rank)
{

}

std::string Card::getRank() const
{
    switch(_rank)
    {
        case ACE:
            return "ACE";
        case KING:
            return "KING";
        case QUEEN:
            return "QUEEN";
        case JACK:
            return "JACK";
        case TWO:
            return "TWO";
        case THREE:
            return "THREE";
        case FOUR:
            return "FOUR";
        case FIVE:
            return "FIVE";
        case SIX:
            return "SIX";
        case SEVEN:
            return "SEVEN";
        case EIGHT:
            return "EIGHT";
        case NINE:
            return "NINE";
        case TEN:
            return "TEN";
    }
}

std::string Card::getSuit() const
{
 switch(_suit)
    {
        case HEARTS: return "HEARTS";
        case DIAMONDS: return "DIAMONDS";
        case CLUBS: return "CLUBS";
        case SPADES: return "SPADES";
    }
}

suitEnum Card::getNumSuit(int suit) {
    switch (suit) {
        case 0:
            return suitEnum::HEARTS;
        case 1:
            return suitEnum::SPADES;
        case 2:
            return suitEnum::CLUBS;
        case 3:
            return suitEnum::DIAMONDS;
    }
}

rankEnum Card::getNumRank(int rank) {
    switch (rank)
    {
        case 0: return rankEnum::ACE;
        case 1: return rankEnum::TWO;
        case 2: return rankEnum::THREE;
        case 3: return rankEnum::FOUR;
        case 4: return rankEnum::FIVE;
        case 5: return rankEnum::SIX;
        case 6: return rankEnum::SEVEN;
        case 7: return rankEnum::EIGHT;
        case 8: return rankEnum::NINE;
        case 9: return rankEnum::TEN;
        case 10: return rankEnum::JACK;
        case 11: return rankEnum::KING;
        case 12: return rankEnum::QUEEN;
    }
    }
std::ostream& operator<<(std::ostream& out, const Card& card) {
    return (out << card.getRank() << " of " << card.getSuit());
}
bool operator<(const Card& lhs,const Card& rhs) {
    return(lhs._rank < rhs._rank);
}

suitEnum Card::getSuitEnum() {
    return _suit;
}

rankEnum Card::getRankEnum() {
    return _rank;
}
//sfml
/*
std::string CardCard::rankToString()
{
    switch(_rank)
    {
        case ACE:
            return "A";
        case KING:
            return "K";
        case QUEEN:
            return "Q";
        case JACK:
            return "J";
        default: return std::to_string(_rank+1);
    }
}

std::string CardCard::suitToString()
{
    switch(_suit)
    {
        case HEARTS: return "images/heart.png";
        case DIAMONDS: return "images/diamonds.png";
        case CLUBS: return "images/club.png";
        case SPADES: return "images/spades.png";
    }
}

void CardCard::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

    states.transform= background.getTransform();
    window.draw(background);
    window.draw(suit,states);
    window.draw(rank1,states);
    window.draw(rank2,states);
}

void CardCard::setFillColor(const sf::Color &color)
{
    rank1.setFillColor(color);
    rank2.setFillColor(color);
}

void CardCard::setSize(sf::Vector2f size)
{

    background.setSize(size);

}

void CardCard::setSize(float width, float height)
{
    setSize({width,height});
}

void CardCard::setPosition(sf::Vector2f position) {
    sf::Transformable::setPosition(position);
    background.setPosition(position);
}

void CardCard::setPosition(float x, float y) {
    sf::Transformable::setPosition({x,y});
    background.setPosition({x,y});
}

void CardCard::init()
{
    setUpBackground();
    setUpRank();
    setUpSuit();
}

void CardCard::setUpBackground()
{
    sf::Vector2f size;
    size.x = 100;
    size.y =170;
    background.setSize({size.x,size.y});
}

void CardCard::setUpRank() {
    if(!font.loadFromFile("font/OpenSans-Bold.ttf"))
        exit(20);
    rank1.setFont(font);
    rank1.setString(rankToString());
    rank1.setCharacterSize(30);
    rank1.setPosition({background.getGlobalBounds().left+5,background.getGlobalBounds().top});

    rank2.setFont(font);
    rank2.setString(rankToString());
    rank2.setCharacterSize(30);
    rank2.setPosition(background.getGlobalBounds().width-5,background.getGlobalBounds().height);
    rank2.rotate(90);

    if(_suit==HEARTS || _suit == DIAMONDS)
    {
        rank1.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);

    }
    if(_suit==CLUBS || _suit == SPADES)
    {
        rank1.setFillColor(sf::Color::Black);
        rank2.setFillColor(sf::Color::Black);
    }
}

void CardCard::setUpSuit() {
    if (!texture.loadFromFile(suitToString()))
        exit(21);
    if (_suit == DIAMONDS) {
        suit.setScale({0.2, 0.2});
    }
    suit.setTexture(texture);
    suit.setPosition(background.getGlobalBounds().width/2-suit.getGlobalBounds().width/2,
                     background.getGlobalBounds().height/2-suit.getGlobalBounds().width/2);

}*/

//
// Created by minau on 10/25/2022.
//

#include "CardCard.h"
sf::Texture CardCard::texture;
sf::Font CardCard::font;

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
        case HEARTS: return "CardCard/images/heart.png";
        case DIAMONDS: return "CardCard/images/diamonds.png";
        case CLUBS: return "CardCard/images/club.png";
        case SPADES: return "CardCard/images/spades.png";
    }
}
CardCard::CardCard() : CardCard(HEARTS, ACE)
{
    init();
}

CardCard::CardCard(suitEnum suit, rankEnum rank) :_suit(suit) ,_rank(rank)
{
    init();
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
    setSize(100,170);
    setPosition(160,85);
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
 if(!font.loadFromFile("CardCard/font/OpenSans-Bold.ttf"))
     exit(20);
    rank1.setFont(font);
    rank1.setString(rankToString());
    rank1.setCharacterSize(30);
    rank1.setPosition({5,0});

    rank2.setFont(font);
    rank2.setString(rankToString());
    rank2.setCharacterSize(30);
    rank2.rotate(180);
    rank2.setPosition(background.getGlobalBounds().width-5,background.getGlobalBounds().height);


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

    }
    






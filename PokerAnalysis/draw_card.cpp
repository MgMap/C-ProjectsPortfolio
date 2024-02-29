//
// Created by minau on 11/14/2022.
//

#include "draw_card.h"
#include "Card.h"
sf::Texture draw_card::texture; //not needed for poker analysis, only draw card assignment
sf::Texture draw_card::heartsTexture, draw_card::diamondsTexture, draw_card::spadesTexture, draw_card::clubsTexture;

sf::Font draw_card::font;

//SFML GRAPHICS FUNCTIONS
//default constructor and constructors
draw_card::draw_card() : draw_card(HEARTS, ACE) {

}

draw_card::draw_card(suitEnum suit, rankEnum rank) : suit(suit), rank(rank) {
    init();
}
//other member functions
std::string draw_card::rankToString()
{
    switch(rank)
    {
        case ACE: return "A";
        case KING: return "K";
        case QUEEN: return "Q";
        case JACK: return "J";
        default: return std::to_string(rank+1);
    }
}

std::string draw_card::suitToString()
{
    //return suit image and change rank color depending on suit type
    switch(suit)
    {
        case HEARTS:
            setFillColor(sf::Color::Red);
            return "PokerAnalysis/images/heart.png";
        case DIAMONDS:
            setFillColor(sf::Color::Red);
            return "PokerAnalysis/images/diamond.png";
        case CLUBS:
            setFillColor(sf::Color::Black);
            return "PokerAnalysis/images/club.png";
        default: //case SPADES
            setFillColor(sf::Color::Black);
            return "PokerAnalysis/images/spades.png";
    }
}

void draw_card::setFillColor(const sf::Color &color)
{
    rank1.setFillColor(color);
    rank2.setFillColor(color);
}

//overload size function
void draw_card::setSize(sf::Vector2f size)
{
    sf::Transformable::setScale(size);
    background.setSize(size);
    suit1.setScale(size);
    rank1.setScale(size);
    rank2.setScale(size);
}

void draw_card::setSize(float width, float height)
{
    setSize({width, height});
}

void draw_card::setPosition(sf::Vector2f position) {
    sf::Transformable::setPosition(position);
    background.setPosition(position);
}

void draw_card::setPosition(float x, float y) {
    setPosition({x, y});
}

void draw_card::init()
{
    setUpBackground();
    setUpRank();
    setUpSuit();

}

void draw_card::setUpBackground()
{
    background.setSize({BG_WIDTH,BG_HEIGHT});
}

//this is the text display on card
void draw_card::setUpRank() {
    if(!font.loadFromFile("PokerAnalysis/font/OpenSans-Bold.ttf"))
        exit(20);
    rank1.setFont(font);
    rank1.setString(rankToString());
    rank1.setCharacterSize(CHAR_SIZE);
    rank1.setPosition({8, 0});

    rank2.setFont(font);
    rank2.setString(rankToString());
    rank2.setCharacterSize(CHAR_SIZE);
    rank2.setPosition({55,80});
    //rotate rank in the bottom right corner
    rank2.rotate(180);
}

void draw_card::setUpSuit() {
    if(!texture.loadFromFile(suitToString()))
        exit(5);
    if(!heartsTexture.loadFromFile("PokerAnalysis/images/heart.png")) {
        exit(10);
    }
    if(!diamondsTexture.loadFromFile("PokerAnalysis/images/diamond.png")) {
        exit(15);
    }
    if(!spadesTexture.loadFromFile("PokerAnalysis/images/spades.png")) {
        exit(20);
    }
    if(!clubsTexture.loadFromFile("pokerAnalysis/images/club.png")) {
        exit(25);
    }
    if(suit == HEARTS) {
        suit1.setTexture(heartsTexture);

    } else if(suit == DIAMONDS) {
        suit1.setTexture(diamondsTexture);

    } else if(suit == SPADES) {
        suit1.setTexture(spadesTexture);

    } else {
        suit1.setTexture(clubsTexture);

    }
    suit1.setPosition({17,20});
    suit1.setScale(SUITSCALE);

}

void draw_card::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    states.transform = getTransform();
    //draw background first
    window.draw(background);
    //draw suits
    window.draw(suit1,states);

    //draw ranks
    window.draw(rank1,states);
    window.draw(rank2,states);
}
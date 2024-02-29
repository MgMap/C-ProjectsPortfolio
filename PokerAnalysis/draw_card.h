//
// Created by minau on 11/14/2022.
//

#ifndef SFML_PROJECT_DRAW_CARD_H
#define SFML_PROJECT_DRAW_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "suitEnum.h"
#include "rankEnum.h"

class draw_card: public sf::Drawable, sf::Transformable, sf::Image {
private:
    suitEnum suit;
    rankEnum rank;

    //constant values
    const float BG_WIDTH = 60, BG_HEIGHT = 80;
    //rank character size
    const unsigned CHAR_SIZE = 10;
    //normal suit scales
    const sf::Vector2f SUITSCALE = {0.5, 0.5}, SMALLSUITSCALE = {0.25, 0.25};

    sf::RectangleShape background;
    sf::Text rank1, rank2;
    sf::Sprite suit1;
    static sf::Texture texture;
    static sf::Texture heartsTexture, diamondsTexture, spadesTexture, clubsTexture;

    void init();

    void setUpBackground();
    void setUpRank();
    void setUpSuit();
public:
    static sf::Font font;
    std::string rankToString();
    std::string suitToString();

    //sfml
    draw_card(suitEnum suit, rankEnum rank);
    draw_card();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x , float y);
};


#endif //SFML_PROJECT_DRAW_CARD_H

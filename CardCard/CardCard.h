//
// Created by minau on 10/25/2022.
//

#ifndef SFML_PROJECT_CARDCARD_H
#define SFML_PROJECT_CARDCARD_H
#include <SFML/Graphics.hpp>
#include "suitEnum.h"
#include "rankEnum.h"

class CardCard :public sf::Drawable, sf::Transformable{
private:

    sf::RectangleShape background;
    sf::Text rank1;
    sf::Text rank2;
    sf::Sprite suit;
    static sf::Texture texture;
    static sf::Font font;
    suitEnum _suit;
    rankEnum _rank;
    std::string rankToString();
    std::string suitToString();
    void init();
    void setUpBackground();
    void setUpRank();
    void setUpSuit();
public:
    CardCard();
    CardCard(suitEnum suit, rankEnum rank);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states)const;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x , float y);
    void flip();
    void set_center();
};


#endif //SFML_PROJECT_CARDCARD_H

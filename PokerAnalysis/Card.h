//
// Created by minau on 10/25/2022.
//

#ifndef SFML_PROJECT_CARD_H
#define SFML_PROJECT_CARD_H
#include <SFML/Graphics.hpp>
#include "suitEnum.h"
#include "rankEnum.h"

class Card {
private:

    suitEnum _suit;
    rankEnum _rank;
    //sfml
   /* sf::RectangleShape background;
    sf::Text rank1;
    sf::Text rank2;
    sf::Sprite suit;
    static sf::Texture texture;
    static sf::Font font;

    std::string rankToString();
    std::string suitToString();
    void init();
    void setUpBackground();
    void setUpRank();
    void setUpSuit();*/
public:
/*//sfml
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states)const;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x , float y);*/
    //for deck
    suitEnum getSuitEnum();
    rankEnum getRankEnum();
    Card(std::string suit, std::string value);
    Card(suitEnum _suit, rankEnum _rank);

    Card();
    std::string getSuit() const;
    std::string getRank() const;
    void setSuit(suitEnum suit);
    void setRank(rankEnum value);
    friend std::ostream& operator<<(std::ostream& out, const Card& card);
    suitEnum getNumSuit(int suit) ;
    rankEnum getNumRank(int rank) ;
    friend bool operator<(const Card& lhs,const Card& rhs);
    };


#endif //SFML_PROJECT_CARDCARD_H

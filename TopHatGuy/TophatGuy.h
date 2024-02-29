//
// Created by minau on 10/19/2022.
//

#ifndef SFML_PROJECT_TOPHATGUY_H
#define SFML_PROJECT_TOPHATGUY_H
#include <SFML/Graphics.hpp>

class TophatGuy : public sf::Drawable, public sf::Transformable{
private:
    sf::RectangleShape top,brim;
    sf::CircleShape face;
    sf::CircleShape triangle;

public:
    TophatGuy();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;// must have this function to be drawable
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
};


#endif //SFML_PROJECT_TOPHATGUY_H

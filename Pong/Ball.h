//
// Created by minau on 10/10/2022.
//

#ifndef SFML_TEMPLATE_FUNCTIONS_H
#define SFML_TEMPLATE_FUNCTIONS_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Paddle.h"

//in header file
class Ball: public sf::CircleShape
{
private:

    sf::Vector2f velocity = {1, 1};

public:
    Ball();
    void bounce();
    //void eventHandler(sf::RenderWindow &window, sf::Event event);
    void bounce(const sf::Vector2u& windowSize);
    void setVelocity(const sf::Vector2f& velocity);

};

#endif //SFML_PROJECT_BALL_H

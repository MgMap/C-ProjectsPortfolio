//
// Created by minau on 12/14/2022.
//

#ifndef SFML_PROJECT_PONG_H
#define SFML_PROJECT_PONG_H
#include "Ball.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>

class Pong :public sf::Drawable
        {
        public:
    Paddle rectangle;
    Paddle rectangle2;
    Ball circle;
    Pong();
    void init();
    void bounce(const sf::Vector2u& windowSize);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_PONG_H

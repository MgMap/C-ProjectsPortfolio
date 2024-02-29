//
// Created by minau on 12/14/2022.
//

#include "Pong.h"

Pong::Pong() {
    init();
}

void Pong::init()
{
    rectangle2.setPosition(940,50);
}

void Pong::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rectangle2.PaddleMoveDown(window.getSize());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rectangle2.PaddleMoveUp(window.getSize());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        rectangle.PaddleMoveDown(window.getSize());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        rectangle.PaddleMoveUp(window.getSize());
    }
}

void Pong::bounce(const sf::Vector2u &windowSize)
{

    sf::FloatRect a = circle.getGlobalBounds();
    sf::FloatRect b = rectangle.getGlobalBounds();
    sf::FloatRect c= rectangle2.getGlobalBounds();
    if(a.intersects(b) || a.intersects(c))
    {
        circle.bounce();
    }
    circle.bounce(windowSize);
}

void Pong::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(circle);
    target.draw(rectangle2);
    target.draw(rectangle);
}

//
// Created by minau on 10/10/2022.
//

#include "Paddle.h"
Paddle::Paddle() : sf::RectangleShape()
{
    //shape yourself like a pong paddle

    setSize({10,100});
    setFillColor(sf::Color::Green);
    setPosition(0,100);
}
void Paddle::PaddleMoveUp(const sf::Vector2u& windowSize)
{
    sf::FloatRect b = getGlobalBounds();
    setVelocity({0, 10});
    if(b.top <= 0) {
        velocity.y =0;
    }
    else{
        velocity.y = -velocity.y;
    }
    sf::RectangleShape::move(velocity);
    }

void Paddle::PaddleMoveDown(const sf::Vector2u& windowSize)
{
    sf::FloatRect b = getGlobalBounds();
    setVelocity({0, -10});
    if(b.top + b.height >= windowSize.y) {
        velocity.y = 0;
    }
    else
    {
        velocity.y = -velocity.y;
    }

    sf::RectangleShape::move(velocity);
}
void Paddle::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}


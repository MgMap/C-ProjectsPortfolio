//
// Created by minau on 10/10/2022.
//
#include "Paddle.h"
#include "Ball.h"
//in functions.cpp

Ball::Ball() : sf::CircleShape() {
    //shape yourself like a pong paddle

    setRadius(10);
    setFillColor(sf::Color::Yellow);
    setPosition({100, 100});
    setVelocity({0.06, 0.06});
}
void Ball::bounce() {
    velocity.x *= -1;
}
void Ball::bounce(const sf::Vector2u& windowSize) {
    sf::FloatRect b = getGlobalBounds();
    if(b.top + b.height >= windowSize.y || b.top <= 0) {
        velocity.y *= -1;
    }

    /*if(b.left + b.width >= windowSize.x || b.left <= 0) {
        velocity.x *= -1;
    }*/

    sf::CircleShape::move(velocity);
}
void Ball::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}

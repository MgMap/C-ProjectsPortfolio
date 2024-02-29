//
// Created by minau on 10/8/2022.
//
#include "function.h"
#include <SFML/Graphics.hpp>

BouncingBall::BouncingBall() {
    float radius = 50;
    circleShape.setRadius(radius);
    circleShape.setOrigin(radius,radius);
    circleShape.setPosition({100,150});
    circleShape.setFillColor(sf::Color::Magenta);
}

void BouncingBall::bounce(const sf::RenderWindow &window) {

}

void BouncingBall::bounce(sf::Vector2i windowSize)
{
    circleShape.move({velocity.x,velocity.y});
    if((circleShape.getPosition().y > (windowSize.y-circleShape.getRadius())) )
    {
        float temp = velocity.x;
        velocity.x = -velocity.y;
        velocity.y = temp;
    }
    else if((circleShape.getPosition().y < circleShape.getRadius()))
    {
        float temp = velocity.y;
        velocity.y= -velocity.x;
        velocity.x = temp;
    }
    else if(circleShape.getPosition().x > (windowSize.x - circleShape.getRadius()))
    {
        float temp = velocity.x;
        velocity.x = -velocity.y;
        velocity.y = temp;

    }
    else if(circleShape.getPosition().x < circleShape.getRadius())
    {
        float temp = velocity.y;
        velocity.y= -velocity.x;
        velocity.x = temp;
    }

}

void BouncingBall::setVelocity(const sf::Vector2f& velocity)
{
    this->velocity = velocity;
}

void BouncingBall::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(circleShape);
}

/*
void BouncingBall::bounce(const sf::Vector2u& windowSize)
{
    sf::FloatRect b = getGlobalBounds();
    if(b.top + b.height >= windowSize.y || b.top <= 0)
    {
        velocity.y = -velocity.y;
    }
    if(b.left + b.width >= windowSize.x || b.left <= 0)
    {
        velocity.x = -velocity.x;
    }
    sf::CircleShape::move(velocity);
}
*/

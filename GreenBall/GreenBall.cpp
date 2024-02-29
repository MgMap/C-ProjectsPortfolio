//
// Created by minau on 12/14/2022.
//

#include "GreenBall.h"

GreenBall::GreenBall()
{
    init();
}

void GreenBall::setFillColor(sf::Color color)
{
    circle.setFillColor(color);
}

void GreenBall::setRadius(float radius)
{
    circle.setRadius(radius);
}

void GreenBall::init()
{
    setFillColor(sf::Color::Green);
    setRadius(300);
}

void GreenBall::draw( sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(circle);
}

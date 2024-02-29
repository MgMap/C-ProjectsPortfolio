//
// Created by minau on 10/19/2022.
//

#include "TophatGuy.h"
TophatGuy::TophatGuy()
{
    setPosition({300,200});
    triangle.setRadius(30);
    triangle.setPointCount(3);
    triangle.rotate(60);
    triangle.setFillColor(sf::Color::Green);
    top.setSize({50,70});
    brim.setSize({90,20});
    face.setRadius(30);
    top.setPosition({5,-85});
    top.setFillColor(sf::Color::Yellow);
    brim.setPosition({-15,-15});
    brim.setFillColor(sf::Color::Cyan);
    //face.setPosition({200,300});
    triangle.setPosition({40,25});
}
void TophatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    states.transform = getTransform();
    window.draw(top,states);
    window.draw(brim,states);
    window.draw(triangle,states);
    window.draw(face);

}

void TophatGuy::setPosition(sf::Vector2f pos) {
    sf::Transformable::setPosition(pos);
    face.setPosition(pos);
}

void TophatGuy::setPosition(float x, float y) {
    setPosition({x,y});
}

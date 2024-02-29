//
// Created by minau on 12/6/2022.
//

#include "Scores.h"

Scores::Scores()
{
    init();
}

void Scores::init()
{
     text.setString("0");
     text.setFont(Fonts::getFont(FLAPPY_FONT));
     text.setCharacterSize(200);
     text.setFillColor(sf::Color::White);
     text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
     //have to change it into portfolio screen width an heigh becuase they are not the same
     text.setPosition(PORTFOLIO_SCREEN_WIDTH/2, PORTFOLIO_SCREEN_HEIGHT/5);
}

void Scores::update(int scores)
{
    text.setString(std::to_string(scores));
    text.setPosition(PORTFOLIO_SCREEN_WIDTH/2, PORTFOLIO_SCREEN_HEIGHT/5);
}

void Scores::draw(sf::RenderTarget &target, sf::RenderStates states)  const
{
    target.draw(text);
}

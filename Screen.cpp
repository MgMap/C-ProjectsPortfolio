//
// Created by minau on 12/8/2022.
//

#include "Screen.h"

Screen::Screen()
{
    setProjectTexture(getProjectEnums(1));
    setProjectString(getProjectEnums(1));
    init();
}
Screen::Screen(int i)
{
    setProjectTexture(getProjectEnums(i));
    setProjectString(getProjectEnums(i));
    init();
}

void Screen::init()
{

    projectText.setFont(Fonts::getFont(OPEN_SANS));
    projectText.setFillColor(sf::Color::Black);
    projectText.setCharacterSize(20);
    setPosition();
}

void Screen::setPosition()
{

    //rightArrow.setPosition(20,20);
    projectText.setPosition(PORTFOLIO_SCREEN_WIDTH/2 - projectText.getGlobalBounds().width/2,
                            3*PORTFOLIO_SCREEN_HEIGHT/4);
    projectPic.setPosition(PORTFOLIO_SCREEN_WIDTH/2 - projectPic.getGlobalBounds().width/2,
                           PORTFOLIO_SCREEN_HEIGHT/7);

}

void Screen::setProjectTexture(projectEnums projectEnums)
{
    switch(projectEnums)
    {
        case 0: projectPic.setTexture(projectTextures::getTexture(GREEN_BALL)); break;
        case 1: projectPic.setTexture(projectTextures::getTexture(BOUNCING_BALL)); break;
        case 2: projectPic.setTexture(projectTextures::getTexture(PONG)) ;break;
        case 3: projectPic.setTexture(projectTextures::getTexture(TOP_HAT_GUY)) ;break;
        case 4: projectPic.setTexture(projectTextures::getTexture(CARD)) ;break;
        case 5: projectPic.setTexture(projectTextures::getTexture(POKER_ANALYSIS)) ;break;
        case 6: projectPic.setTexture(projectTextures::getTexture(FLAPPY_BIRD)); break;
    }
}

void Screen::setProjectString(projectEnums projectEnums)
{
    switch(projectEnums) {
        case 0: projectText.setString("      This is just a Green Ball"
                                      "\n(Click Button To see a green ball)");break;
        case 1: projectText.setString("                 BOUNCING BALL\n"
                                      "(Click Button To see a ball bouncing)");break;
        case 2: projectText.setString("                                      PONG\n"
                                      "(once the ball go beyound the window it never comes back)");break;
        case 3: projectText.setString("TOP HAT GUY\n"
                                      "       (???)");break;
        case 4: projectText.setString("   CARD\n"
                                      "(just card)");break;
        case 5: projectText.setString("     POKER ANALYSIS\n"
                                      "(many cards with some math)");break;
        case 6: projectText.setString("       FLAPPY BIRD\n"
                                      "a bird flying though pipes?");break;
    }
}
projectEnums Screen::getProjectEnums(int number)
{
    //this function is to assit setFunctions
    switch(number) {
        case 0: return GREEN_BALL;
        case 1: return BOUNCING_BALL;
        case 2: return PONG;
        case 3: return TOP_HAT_GUY;
        case 4: return CARD;
        case 5: return POKER_ANALYSIS;
        case 6: return FLAPPY_BIRD;
    }
}
void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(projectText);
    target.draw(projectPic);
}
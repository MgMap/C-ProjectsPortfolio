//
// Created by minau on 12/15/2022.
//

#include "runProgram.h"

runPrograms::runPrograms()
{
    //make a window
    sf::RenderWindow window(sf::VideoMode(PORTFOLIO_SCREEN_WIDTH,PORTFOLIO_SCREEN_HEIGHT, 60), "Min Portfolio");
    //to check if to run portfolio or project
    okay = true;
    setPosition();
    Portfolio(window,GREEN_BALL);
}

void runPrograms::setPosition()
{
    Button.setTexture(Textures::getTexture(OPEN_PROJECT));
    Button.setScale(0.3,0.3);
    Button.setPosition(PORTFOLIO_SCREEN_WIDTH/2 - Button.getGlobalBounds().width/2,
                       6*PORTFOLIO_SCREEN_HEIGHT/7);

    //left arrow
    leftArrow.setTexture(Textures::getTexture(ARROW));
    leftArrow.setOrigin(leftArrow.getGlobalBounds().width/2,
                        leftArrow.getGlobalBounds().height/2);
    leftArrow.rotate(180);

    //right arrow
    rightArrow.setTexture(Textures::getTexture(ARROW));
    rightArrow.setOrigin(rightArrow.getGlobalBounds().width/2,
                         rightArrow.getGlobalBounds().height/2);

    leftArrow.setScale(0.5,0.5);
    rightArrow.setScale(0.5,0.5);
    leftArrow.setPosition(100,9*PORTFOLIO_SCREEN_HEIGHT/10);
    //leftArrow.setPosition(-10,-10); just checking if it is drawing
    rightArrow.setPosition(PORTFOLIO_SCREEN_WIDTH- 100,
                           9*PORTFOLIO_SCREEN_HEIGHT/10);
}

void runPrograms::Portfolio(sf::RenderWindow &window,projectEnums projectEnum)
{
    if (okay)
    {
        std::vector<Screen> screens;
        for (int i = 0; i < 7; i++) {
            Screen screen(i);
            screens.push_back(screen);
        }
        auto iter = screens.begin();
        int counter = 0;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| MouseEvents::isClicked(leftArrow,window))
                {
                    if (iter != screens.begin())
                    {
                        --iter;counter--;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||MouseEvents::isClicked(rightArrow,window))
                {
                    if (iter != screens.end() - 1)
                    {
                        ++iter;counter++;
                    }
                }
                if(MouseEvents::isClicked(Button,window))
                {
                    okay = false;
                    projectEnum = screens.at(counter).getProjectEnums(counter);
                    runProject(window,projectEnum);
                }
            }
            window.clear(sf::Color::White);
            window.draw(*iter);
            window.draw(leftArrow);
            window.draw(rightArrow);
            window.draw(Button);
            window.display();
        }
    }
}

void runPrograms::initGreenBall(sf::RenderWindow &window)
{
    GreenBall ball;
    windowEventHandler(window, ball, sf::Color::Black);

}

void runPrograms::initBouncingBall(sf::RenderWindow &window)
{
    BouncingBall bouncingBall;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            eventHandler(window, event);
        }
        bouncingBall.bounce({PORTFOLIO_SCREEN_WIDTH, PORTFOLIO_SCREEN_HEIGHT});
        window.clear(sf::Color::Black);
        window.draw(bouncingBall);
        window.display();
    }
}

void runPrograms::initPong(sf::RenderWindow &window) {
    Pong pong;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            eventHandler(window, event);
            pong.eventHandler(window, event);
        }

        pong.bounce({PORTFOLIO_SCREEN_WIDTH, PORTFOLIO_SCREEN_HEIGHT});
        window.clear(sf::Color::Black);
        window.draw(pong);
        window.display();
    }
}

void runPrograms::initTopHatGuy(sf::RenderWindow &window)
{
    TophatGuy tophatGuy;
    windowEventHandler(window, tophatGuy, sf::Color::Black);
}

void runPrograms::initCard(sf::RenderWindow &window)
{
    CardCard card(HEARTS,ACE);
    windowEventHandler(window, card, sf::Color::Green);
}

void runPrograms::initPokerAnalysis(sf::RenderWindow &window)
{
    srand(time(NULL));
    draw_cardHand ch;
    windowEventHandler(window, ch, sf::Color::Green);
}

void runPrograms::initFlappyBird(sf::RenderWindow &window) {
    GameState flap;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            eventHandler(window, event);
            flap.eventHandler(window, event);
        }
        window.clear();
        flap.update();
        window.draw(flap);
        window.display();
    }
}
void runPrograms::eventHandler(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type == sf::Event::Closed){
        window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
        runPrograms portfolio;
    }
}

//to avoid rewritng all this
template<class T>
void runPrograms::windowEventHandler(sf::RenderWindow &window, const T &obj, sf::Color color)
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            eventHandler(window, event);
        }
        window.clear(color);
        window.draw(obj);
        window.display();
    }
}

void runPrograms::runProject(sf::RenderWindow &window,const projectEnums& projectIndex)
{
    switch (projectIndex)
    {
        case 0:
            initGreenBall(window);
            break;
        case 1:
            initBouncingBall(window);
            break;
        case 2:
            initPong(window);
            break;
        case 3:
            initTopHatGuy(window);
            break;
        case 4:
            initCard(window);
            break;
        case 5:
            initPokerAnalysis(window);
            break;
        case 6:
            initFlappyBird(window);
            break;
    }
}
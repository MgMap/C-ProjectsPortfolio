//
// Created by minau on 12/15/2022.
//

#ifndef SFML_PROJECT_RUNPROGRAM_H
#define SFML_PROJECT_RUNPROGRAM_H
#include <iostream>
#include "Screen.h"
#include "MouseEvent.h"
#include <SFML/Graphics.hpp>
#include "FlappyBird/DEFINITIONS.h"
#include "FlappyBird/GameState.h"
#include "BouncingBall/function.h"
#include "CardCard/CardCard.h"
#include "GreenBall/GreenBall.h"
#include "PokerAnalysis/draw_cardHand.h"
#include "Pong/pong.h"
#include "TopHatGuy/TophatGuy.h"

class runPrograms:public Screen {
public:
    runPrograms();
    void Portfolio(sf::RenderWindow& window, projectEnums projectEnums);
    void setPosition();
private:
    bool okay;
    sf::Sprite rightArrow;
    sf::Sprite leftArrow;
    sf::Sprite Button;

    static void initGreenBall(sf::RenderWindow& window);
    static void initBouncingBall(sf::RenderWindow& window);
    static void initPong(sf::RenderWindow& window);
    static void initTopHatGuy(sf::RenderWindow& window);
    static void initCard(sf::RenderWindow& window);
    static void initPokerAnalysis(sf::RenderWindow& window);
    static void initFlappyBird(sf::RenderWindow& window);
    static void eventHandler(sf::RenderWindow& window, sf::Event& event);
    template<class T>
    static void windowEventHandler(sf::RenderWindow& window, const T& obj, sf::Color color);
    static void runProject(sf::RenderWindow& window, const projectEnums& projectIndex);
};


#endif //SFML_PROJECT_RUNPROGRAM_H

//
// Created by minau on 10/10/2022.
//

#ifndef SFML_PROJECT_PADDLE_H
#define SFML_PROJECT_PADDLE_H
#include <SFML\Graphics.hpp>
#include <iostream>

class Paddle :public sf::RectangleShape
        {
        private:
         sf::Vector2f velocity = {0, 0};
        public:
            Paddle();
           void PaddleMoveUp(const sf::Vector2u& windowSize);
    void PaddleMoveDown(const sf::Vector2u& windowSize);
    void setVelocity(const sf::Vector2f& velocity);
};


#endif //SFML_PROJECT_PADDLE_H

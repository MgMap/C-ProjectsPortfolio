//
// Created by minau on 12/14/2022.
//

#ifndef SFML_PROJECT_GREENBALL_H
#define SFML_PROJECT_GREENBALL_H
#include <SFML/Graphics.hpp>

class GreenBall :public sf::Drawable
        {
        private:
    sf::CircleShape circle;
        public:
            GreenBall();
            void init();
            void setFillColor(sf::Color color);
            void setRadius(float radius);
            void draw( sf::RenderTarget& target,sf::RenderStates states) const;
};


#endif //SFML_PROJECT_GREENBALL_H

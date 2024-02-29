//
// Created by minau on 10/8/2022.
//
#include <SFML/Graphics.hpp>

#ifndef SFML_PROJECT_FUNCTION_H
#define SFML_PROJECT_FUNCTION_H
//void bounce(sf::Vector2i windowSize, sf::CircleShape ball, sf::Vector2f& speed);

// Dave's solution
class BouncingBall : public sf::CircleShape
  {
  private:
      sf::Vector2f velocity = {1,1};
        sf::CircleShape circleShape;
  public:
      BouncingBall();
      void bounce(const sf::RenderWindow& window);
      //void bounce(const sf::Vector2u& windowSize);
      void setVelocity(const sf::Vector2f& velocity);
      void bounce(sf::Vector2i windowSize);
      void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 };



#endif //SFML_PROJECT_FUNCTION_H

//
// Created by minau on 12/8/2022.
//

#ifndef SFML_PROJECT_SCREEN_H
#define SFML_PROJECT_SCREEN_H
#include "PROJECTDEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include "FlappyBird/DEFINITIONS.h"
#include <string>
#include "projectTextures.h"
#include "FlappyBird/Fonts.h"
#include "FlappyBird/Textures.h"
#include "States.h"

class Screen : public sf::Drawable, public States {
private:
    sf::Text text;
    //std::vector<sf::Sprite> portfolioprojects;

    sf::Sprite projectPic;
    sf::Text projectText;
public:

    Screen();
    Screen(int i);
    void init();
    void setPosition();
    static projectEnums getProjectEnums(int number);

    void setProjectTexture(enum projectEnums);
    void setProjectString(enum projectEnums);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //SFML_PROJECT_SCREEN_H

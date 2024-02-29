 cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PokerAnalysis/font PokerAnalysis/images PokerAnalysis/Card.h PokerAnalysis/Card.cpp PokerAnalysis/CardHand.h PokerAnalysis/CardHand.cpp PokerAnalysis/CardHandScorer.cpp PokerAnalysis/CardHandScorer.h PokerAnalysis/Deck.cpp PokerAnalysis/Deck.h PokerAnalysis/draw_card.h PokerAnalysis/draw_card.cpp PokerAnalysis/draw_cardHand.cpp PokerAnalysis/draw_cardHand.h PokerAnalysis/PokerScore.cpp PokerAnalysis/PokerScore.h PokerAnalysis/rankEnum.h PokerAnalysis/suitEnum.h PokerAnalysis/test.cpp PokerAnalysis/test.h BouncingBall/function.cpp BouncingBall/function.h TopHatGuy/TophatGuy.cpp TopHatGuy/TophatGuy.h CardCard/font CardCard/images CardCard/CardCard.cpp CardCard/CardCard.h CardCard/rankEnum.h CardCard/suitEnum.h Pong/Ball.cpp Pong/Ball.h Pong/Paddle.cpp Pong/Paddle.h FlappyBird/SplashState.cpp FlappyBird/SplashState.h FlappyBird/TextureEnum.h FlappyBird/Textures.cpp FlappyBird/Textures.h FlappyBird/Fonts.cpp FlappyBird/Fonts.h FlappyBird/fontsEnum.h FlappyBird/DEFINITIONS.h FlappyBird/GameState.cpp FlappyBird/GameState.h FlappyBird/MainMenuState.cpp FlappyBird/MainMenuState.h States.cpp States.h FlappyBird/stateEnum.h MouseEvent.cpp MouseEvent.h FlappyBird/Bird.cpp FlappyBird/Bird.h FlappyBird/BirdState.h FlappyBird/Land.cpp FlappyBird/Land.h FlappyBird/Pipe.cpp FlappyBird/Pipe.h FlappyBird/Collisions.cpp FlappyBird/Collisions.h FlappyBird/GameStates.h FlappyBird/Scores.cpp FlappyBird/Scores.h FlappyBird/Flash.cpp FlappyBird/Flash.h FlappyBird/GameOver.cpp FlappyBird/GameOver.h Screen.cpp Screen.h projectEnums.h projectTextures.cpp projectTextures.h GreenBall/GreenBall.cpp GreenBall/GreenBall.h Pong/Pong.cpp Pong/Pong.h PROJECTDEFINITIONS.h runProgram.cpp runProgram.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
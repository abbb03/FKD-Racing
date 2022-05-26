#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Car.h"
#include "MenuSystem.h"
#include "EnemySystem.h"
#include "ScoreSystem.h"

class Game
{
public:
    Game();
    ~Game();
    
    enum GameState { MENU, GAME, END };

    void start();

private:
    sf::RenderWindow* m_window;
    sf::Event m_event;
    sf::VideoMode m_videoMode;

    int m_gameSpeed;
    GameState m_gameState;
    Car* m_car;
    EnemySystem* m_enemySystem;
    ScoreSystem* m_scoreSystem;
    MenuSystem* m_menuSystem;

    void initGameState();
    void initVariables();
    void initCar();
    void initMenu();
    void initEnemySystem();
    void initScoreSystem();
    void initWindow();
    void update(float dt);
    void updateGameState(float dt);
    void updateMenuState(float dt);
    void updateGameOverState(float dt);
    void draw();
};

#endif

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Car.h"
#include "EnemySystem.h"
#include "ScoreSystem.h"

class Game
{
private:
    sf::RenderWindow* m_window;
    sf::Event m_event;
    sf::VideoMode m_videoMode;

    int m_gameSpeed;

    Car* m_car;
    EnemySystem* m_enemySystem;
    ScoreSystem* m_scoreSystem;

    void initVariables();
    void initCar();
    void initEnemySystem();
    void initScoreSystem();
    void initWindow();
    void update(float dt);
    void draw();

public:
    Game();
    ~Game();
    
    void start();
};

#endif
#include "Constants.h"

#include "Game.h"

Game::Game()
{
    initVariables();
    initWindow();
    initMenu();
}

Game::~Game()
{
    delete this->m_window;
}

void Game::start()
{
    sf::Clock clock;
    while (m_window->isOpen())
    {
        float dt = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        dt /= m_gameSpeed;

        update(dt);
        draw();

        while (this->m_window->pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
            {
                this->m_window->close();
            }
        }
    }
}

void Game::initWindow()
{
    m_videoMode.height = WINDOW_HEIGHT;
    m_videoMode.width = WINDOW_WIDTH;

    this->m_window = new sf::RenderWindow(m_videoMode, "test", sf::Style::Close);
}

void Game::initVariables()
{
    this->m_window = nullptr;
    m_gameSpeed = GAME_SPEED;
    m_gameState = MENU;
}

void Game::initGameState()
{
    initCar();
    initEnemySystem();
    initScoreSystem();
}

void Game::initCar()
{
    m_car = new Car();
}

void Game::initEnemySystem()
{
    m_enemySystem = new EnemySystem();
}

void Game::initScoreSystem()
{
    m_scoreSystem = new ScoreSystem();
}

void Game::initMenu()
{
    m_menuSystem = new MenuSystem();
}

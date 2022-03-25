#include "Constants.h"

#include "Game.h"

Game::Game()
{
    initVariables();
    initCar();
    initEnemySystem();
    initEnemies();
    initScoreSystem();
    initWindow();
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

        while (this->m_window->pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
            {
                this->m_window->close();
            }
        }

        update(dt);
        draw();
    }
}

void Game::initVariables()
{
    this->m_window = nullptr;
    m_gameSpeed = GAME_SPEED;
}

void Game::initCar()
{
    m_car = new Car();
}

void Game::initEnemySystem()
{
    srand(time(0));
    m_enemySystem = new EnemySystem();
}

void Game::initEnemies()
{
    m_enemySystem->createEnemies();
}

void Game::initScoreSystem()
{
    m_scoreSystem = new ScoreSystem();
    m_scoreSystem->initText();
}

void Game::initWindow()
{
    m_videoMode.height = WINDOW_HEIGHT;
    m_videoMode.width = WINDOW_WIDTH;

    this->m_window = new sf::RenderWindow(m_videoMode, "test", sf::Style::Close);
    this->m_window->setFramerateLimit(FPS);
}

#include "Game.h"

void Game::update(float dt)
{
    switch(m_gameState)
    {
        case MENU:
            updateMenuState(dt);
            break;
        case GAME:
            updateGameState(dt);
            break;
        case END:
            m_window->close();
            break;
        default:
            break;
    }
}

void Game::updateGameState(float dt)
{
        m_car->update(dt);
        m_enemySystem->update(dt);
        if (m_enemySystem->checkCollision(m_car->getSprite()))
        {
            m_gameState = END;
        }
        m_scoreSystem->scoreUpdate(dt);
    
}


void Game::updateMenuState(float dt)
{
    m_menuSystem->update(dt);  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        initGameState();
        m_gameState = GAME;
    }
}

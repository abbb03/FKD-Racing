#include "Game.h"

void Game::update(float dt)
{
    m_car->update(dt);
    m_enemySystem->update(dt);
    if (m_enemySystem->checkCollision(m_car->getSprite()))
    {
        this->m_window->close();
    }
    m_scoreSystem->scoreUpdate(dt);
}

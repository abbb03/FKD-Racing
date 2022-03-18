#include "Game.h"

void Game::update(float dt)
{
    m_car->update(dt);
    m_enemySystem->update(dt);
    m_scoreSystem->scoreUpdate(dt);
}

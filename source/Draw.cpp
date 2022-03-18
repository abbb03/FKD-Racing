#include "Game.h"

void Game::draw()
{
    m_window->clear(sf::Color::White);

    m_car->draw(m_window);
    m_enemySystem->draw(m_window);
    m_scoreSystem->draw(m_window);

    m_window->display();
}
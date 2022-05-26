#include "Game.h"

void Game::draw()
{
    m_window->clear(sf::Color::White);

    switch (m_gameState)
    {
        case (MENU):
            m_menuSystem->draw(m_window);
            m_window->display();
            break;
        case (GAME):
            m_car->draw(m_window);
            m_enemySystem->draw(m_window);
            m_scoreSystem->draw(m_window);
            m_window->display();
            break;
        default:
            break;
    }
}

#include "Constants.h"

#include "EnemySystem.h"

EnemySystem::EnemySystem()
{

}

EnemySystem::~EnemySystem()
{

}

void EnemySystem::update(float dt)
{
    // enemyRefresh();
    updateEnemies(dt);
}

void EnemySystem::enemyRefresh()
{
    if (clock1.getElapsedTime().asSeconds() > 1)
    {
        createEnemies();
        clock1.restart();
    }
}

void EnemySystem::updateEnemies(float dt)
{
    for (m_enemy = m_enemies.begin(); m_enemy != m_enemies.end();)
    {
        (*m_enemy)->update(dt);
        if (!enemyExists(m_enemy))
        {
            m_enemy = deleteEnemy(m_enemy);
            enemyRefresh();
            printf("%ld", m_enemies.size());
        }

        else
        {
            m_enemy++;
        }
    }
}

void EnemySystem::createEnemies()
{
    int randomY = rand() % ((WINDOW_WIDTH / STEP));
    m_enemies.push_back(new Enemy(randomY * STEP));
}

bool EnemySystem::enemyExists(std::list<Enemy*>::iterator m_enemy)
{
    return ((*m_enemy)->getSprite().getPosition().y < WINDOW_HEIGHT);
}

std::list<Enemy*>::iterator EnemySystem::deleteEnemy(std::list<Enemy*>::iterator m_enemy)
{
    m_enemy = m_enemies.erase(m_enemy);
    delete *m_enemy;
    return m_enemy;
}

void EnemySystem::draw(sf::RenderWindow* window)
{
    for (m_enemy = m_enemies.begin(); m_enemy != m_enemies.end(); m_enemy++)
    {
        window->draw((*m_enemy)->getSprite());
    }
}

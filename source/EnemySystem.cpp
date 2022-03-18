#include "Constants.h"

#include "EnemySystem.h"

EnemySystem::EnemySystem()
{

}

EnemySystem::~EnemySystem()
{

}

void EnemySystem::createEnemies(int count)
{
    for (int i = 0; i < count; i++)
    {
        int randomY = rand() % ((WINDOW_WIDTH / STEP));
        m_enemies.push_back(new Enemy(randomY * STEP));
    }
}

void EnemySystem::update(float dt)
{
    if (m_enemies.size() < 1)
    {
        createEnemies(1 + rand() % 3);
    }
    
    updateEnemies(dt);
}

void EnemySystem::draw(sf::RenderWindow* window)
{
    for (m_enemy = m_enemies.begin(); m_enemy != m_enemies.end(); m_enemy++)
    {
        window->draw((*m_enemy)->getSprite());
    }
}

void EnemySystem::updateEnemies(float dt)
{
    for (m_enemy = m_enemies.begin(); m_enemy != m_enemies.end();)
    {
        (*m_enemy)->update(dt);
        if (enemyExists(m_enemy))
        {
            m_enemy = deleteEnemy(m_enemy);
        }
        else
        {
            m_enemy++;
        }
    }
}

bool EnemySystem::enemyExists(std::list<Enemy*>::iterator m_enemy)
{
    return ((*m_enemy)->getSprite().getPosition().y > WINDOW_HEIGHT);
}

std::list<Enemy*>::iterator EnemySystem::deleteEnemy(std::list<Enemy*>::iterator m_enemy)
{
    m_enemy = m_enemies.erase(m_enemy);
    delete *m_enemy;
    return m_enemy;
}
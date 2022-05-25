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
    enemySpawner();
    updateEnemies(dt);
}

void EnemySystem::enemySpawner()
{
    if (m_spawnClock.getElapsedTime().asSeconds() > 0.5)
    {
        createEnemy();
        m_spawnClock.restart();
    }
}

bool EnemySystem::checkCollision(sf::Sprite sprite)
{
    for (m_enemy = m_enemies.begin(); m_enemy != m_enemies.end(); m_enemy++)
    {
        return sprite.getGlobalBounds().intersects((*m_enemy)->getSprite().getGlobalBounds());
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
        }
        else
        {
            m_enemy++;
        }
    }
}

void EnemySystem::createEnemy()
{
    int random = rand() % ((WINDOW_WIDTH / STEP));
    Enemy* newEnemy = new Enemy(random * STEP, ~STEP);
    m_enemies.push_back(newEnemy);
}

bool EnemySystem::enemyExists(std::list<Enemy*>::iterator m_enemy)
{
    return ((*m_enemy)->getSprite().getPosition().y) < WINDOW_HEIGHT;
}

std::list<Enemy*>::iterator EnemySystem::deleteEnemy(std::list<Enemy*>::iterator m_enemy)
{
    delete *m_enemy;
    m_enemy = m_enemies.erase(m_enemy);
    return m_enemy;
}

void EnemySystem::draw(sf::RenderWindow* window)
{
    for (m_enemy = m_enemies.begin(); m_enemy != m_enemies.end(); m_enemy++)
    {
        window->draw((*m_enemy)->getSprite());
    }
}


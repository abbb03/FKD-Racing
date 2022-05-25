#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include <list>

#include <SFML/Graphics.hpp>

#include "Enemy.h"

class EnemySystem
{
private:
    std::list<Enemy*> m_enemies;
    std::list<Enemy*>::iterator m_enemy;
    sf::Clock m_spawnClock;

    void enemySpawner();
    void updateEnemies(float dt);
    void createEnemy();
    bool enemyExists(std::list<Enemy*>::iterator m_enemy);
    std::list<Enemy*>::iterator deleteEnemy(std::list<Enemy*>::iterator m_enemy);
public:
    EnemySystem();
    ~EnemySystem();

    bool checkCollision(sf::Sprite sprite);
    void update(float dt);
    void draw(sf::RenderWindow* window);
};

#endif

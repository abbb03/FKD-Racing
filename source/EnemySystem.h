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

public:
    EnemySystem();
    ~EnemySystem();

    void createEnemies(int count);
    bool enemyExists(std::list<Enemy*>::iterator m_enemy);
    std::list<Enemy*>::iterator deleteEnemy(std::list<Enemy*>::iterator m_enemy);
    void update(float dt);
    void draw(sf::RenderWindow* window);
    void updateEnemies(float dt);
};

#endif
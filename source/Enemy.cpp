#include <stdlib.h>

#include "Enemy.h"

Enemy::Enemy()
{
    loadTexture();
    initVariables();
    setSprite();
}

Enemy::Enemy(int xPosition)
{
    loadTexture();
    initVariables(xPosition);
    setSprite();
}

void Enemy::loadTexture()
{
    m_Texture.loadFromFile("images/car.png");
}

void Enemy::initVariables()
{
    m_Position.x = 0;
    m_Position.y = 0;
}

void Enemy::initVariables(int xPosition)
{
    m_Position.x = xPosition;
    m_Position.y = 0;
}

void Enemy::setSprite()
{
    m_Sprite.setTexture(m_Texture);
}

sf::Sprite Enemy::getSprite()
{
    return m_Sprite;
}

void Enemy::update(float dt)
{
    m_Position.y += 0.2 * dt;
    m_Sprite.setPosition(m_Position);
}

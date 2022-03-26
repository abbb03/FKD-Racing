#include <stdlib.h>

#include "Enemy.h"
#include "Constants.h"

Enemy::Enemy()
{
    loadTexture();
    initPosition();
    setSprite();
}

Enemy::Enemy(int xPosition, int yPosition)
{
    loadTexture();
    setPosition(xPosition, yPosition);
    setSprite();
}

void Enemy::loadTexture()
{
    m_Texture.loadFromFile("images/car.png");
}

void Enemy::initPosition()
{
    m_Position.x = 0;
    m_Position.y = 0;
}

void Enemy::setPosition(int xPosition, int yPosition)
{
    m_Position.x = xPosition;
    m_Position.y = yPosition;
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
    m_Position.y += 0.1 * dt;
    m_Sprite.setPosition(m_Position);
}

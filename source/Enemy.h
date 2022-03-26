#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;

    sf::Vector2f m_Position;

    void loadTexture();
    void initPosition();
    void setPosition(int xPosition, int yPosition);
    void setSprite();

public:
    Enemy();
    Enemy(int xPosition, int yPosition);

    sf::Sprite getSprite();
    void update(float dt);
};

#endif
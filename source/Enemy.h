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
    void initVariables();
    void initVariables(int xPosition);
    void setSprite();

public:
    Enemy();
    Enemy(int xPosition);

    sf::Sprite getSprite();
    void update(float dt);
};

#endif
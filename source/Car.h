#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>

class Car
{
private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;

    sf::Vector2f m_Position;

    void loadTexture();
    void initVariables();
    void setSprite();

public:
    Car();
    ~Car();

    sf::Sprite getSprite();
    void update(float dt);
    void draw(sf::RenderWindow* window);
};

#endif
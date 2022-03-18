#include "Constants.h"

#include "Car.h"

Car::Car()
{
    loadTexture();
    initVariables();
    setSprite();
}

Car::~Car()
{
}

void Car::initVariables()
{
    m_Position.x = WINDOW_WIDTH / 2;
    m_Position.y = WINDOW_HEIGHT - m_Texture.getSize().y;
}

void Car::loadTexture()
{
    m_Texture.loadFromFile("images/car.png");
}

void Car::setSprite()
{
    m_Sprite.setTexture(m_Texture);
}

sf::Sprite Car::getSprite()
{
    return m_Sprite;
}

void Car::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_Position.x >= 0)
    {
        m_Position.x -= 0.1 * dt;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_Position.x <= WINDOW_WIDTH - m_Texture.getSize().x)
    {
        m_Position.x += 0.1 * dt;
    }
    m_Sprite.setPosition(m_Position);
}

void Car::draw(sf::RenderWindow* window)
{
    window->draw(this->getSprite());
}
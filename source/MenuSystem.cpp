#include "MenuSystem.h"

MenuSystem::MenuSystem()
{
    initText();
}

void MenuSystem::initText()
{
    if(!font.loadFromFile("fonts/CubikeScript.otf"))
    {
        printf("Font load error");
    }
    
    setTextStyle(&startText);
    startText.setPosition(22.f, 128.f);
    startText.setString("Start");

    setTextStyle(&quitText);
    quitText.setPosition(22.f, 224.f); 
    quitText.setString("Quit");
}

void MenuSystem::draw(sf::RenderWindow* window)
{
    window->draw(startText);
    window->draw(quitText);
}

void MenuSystem::setTextStyle(sf::Text* text)
{
    (*text).setFont(font);
    (*text).setCharacterSize(64);
    (*text).setFillColor(sf::Color::Red);
    (*text).setStyle(sf::Text::Bold);
}

void MenuSystem::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        initGameState();
        m_gameState = GAME;
    }
}


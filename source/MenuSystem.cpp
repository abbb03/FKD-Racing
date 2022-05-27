#include "MenuSystem.h"

MenuSystem::MenuSystem()
{
    choice = START;
    timer = 0.f;
    initText();
}

void MenuSystem::initText()
{
    if(!font.loadFromFile("fonts/CubikeScript.otf"))
    {
        printf("Font load error");
    }
    
    setTextStyle(&startText);
    startText.setFillColor(sf::Color::Green);
    startText.setPosition(22.f, 128.f);
    startText.setString("Start");

    setTextStyle(&quitText);
    quitText.setFillColor(sf::Color::Red);
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
    (*text).setStyle(sf::Text::Bold);
}

void MenuSystem::update(float dt)
{
    timer += dt;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && timer > 250.f)
    {
        switch (choice)
        {
            case START:
            {
                startText.setFillColor(sf::Color::Red);
                quitText.setFillColor(sf::Color::Green);
                timer = 0.f;
                choice = QUIT;
                break;
            }
            case QUIT:
            {
                startText.setFillColor(sf::Color::Green);
                quitText.setFillColor(sf::Color::Red);
                timer = 0.f;
                choice = START;
                break;
            }
        }
    }
}


#include "ScoreSystem.h"

#include <sstream>

ScoreSystem::ScoreSystem()
{
    initVariables();
    initText();
}

void ScoreSystem::initVariables()
{
    score = 0;
    timer = 0;
}

void ScoreSystem::initText()
{
    if(!font.loadFromFile("fonts/CubikeScript.otf"))
    {
        printf("Font load error");
    }
    
    scoreText.setFont(font);
    scoreText.setCharacterSize(32);
    scoreText.setFillColor(sf::Color::Red);
    scoreText.setStyle(sf::Text::Bold);
}

void ScoreSystem::draw(sf::RenderWindow* window)
{
    window->draw(scoreText);
}

void ScoreSystem::scoreUpdate(float dt)
{
    timer += dt / 200;
    if (timer > 3)
    {
        score++;
        std::ostringstream playerScoreString; 
        playerScoreString << score;
        scoreText.setString("Score: " + playerScoreString.str());
        timer = 0;
    }
}

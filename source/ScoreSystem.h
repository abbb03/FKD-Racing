#ifndef SCORESYSTEM_H
#define SCORESYSTEM_H

#include <SFML/Graphics.hpp>

class ScoreSystem
{
private:
    sf::Text scoreText;
    sf::Font font;
    int score;
    float timer;
    
public:
    ScoreSystem();

    void initVariables();
    void initText();
    void draw(sf::RenderWindow* window);
    void scoreUpdate(float dt);
};

#endif
#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include <SFML/Graphics.hpp>

class MenuSystem
{
private:
    sf::Text startText;
    sf::Text quitText;
    sf::Font font;
    void initText();
    void setTextStyle(sf::Text* text); 
    enum Choice { START, QUIT };
public:
    MenuSystem();
    
    

    void draw(sf::RenderWindow* window);
    void update(float dt);
};

#endif

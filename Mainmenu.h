#pragma once
#include "GO.h"
#include <SFML/Graphics.hpp>

class Mainmenu
{
public:
	Mainmenu(sf::RenderWindow &window);
	~Mainmenu(void);

	sf::RenderWindow & window;

	void MenuUpdate(sf::RenderWindow &window);
private:

	int shape;

	sf::Texture *tex;
	sf::Texture texturesheet;

};


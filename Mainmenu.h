#pragma once
#include "GO.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class Mainmenu
{
public:
	Mainmenu(sf::RenderWindow &window);
	~Mainmenu(void);

	sf::RenderWindow & window;

	int MenuUpdate(sf::RenderWindow &window);

private:

	bool shape;

	sf::Texture *tex;
	sf::Texture texturesheet;

	int laivaLKM;
	sf::Event _event;
};


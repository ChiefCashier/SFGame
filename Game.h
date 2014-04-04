#pragma once
#include "Update.h"
#include "Mainmenu.h"
#include <SFML/Graphics.hpp>

class Game
{
public:

	Game(void);
	~Game(void);
	void GameLoop();
	void MenuScreen();

	
	static sf::Texture *tex;

private:

	
	sf::Texture texturesheet;

	bool isRunning;

	static sf::RenderWindow window;

	
};


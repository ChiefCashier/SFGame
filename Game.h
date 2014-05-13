#pragma once
#include "Update.h"
#include "Mainmenu.h"
#include "VictoryScreen.h"
#include "LoadingScreen.h"
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

	static sf::RenderWindow window;

	
};


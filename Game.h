#pragma once
#include "Update.h"
#include <SFML/Graphics.hpp>

class Game
{
public:

	Game(void);
	~Game(void);
	void GameLoop();
	void MenuScreen();

private:

	sf::Texture *tex;

	bool isRunning;

	Update U;

	std::vector<Ship> shipvector;
	std::vector<Cannonball*> ballvector;

	std::vector<Ship>::iterator si;
	std::vector<Cannonball*>::iterator ci;
};


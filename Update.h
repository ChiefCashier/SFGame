#pragma once
#include "Cannonball.h"
#include "Ship.h"
#include <SFML/Graphics.hpp>

class Update
{
public:

	Update(sf::RenderWindow & window);
	//~Update(void);

	void GameUpdate(sf::RenderWindow & window);

	bool Collision();

	void Input(std::vector<Ship*>::iterator si);

	static std::vector<Ship*> shipvector;
	static std::vector<Ship*>::iterator si;

	std::vector<Cannonball*>::iterator ci;
	std::vector<Cannonball*> ballvector;

	sf::RenderWindow & window;

protected:

	sf::Clock clock;
	sf::Time elapsed1;
	sf::Texture *tex;
	sf::Texture texturesheet;
	
	int loseCounter;

};


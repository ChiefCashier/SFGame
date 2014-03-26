#pragma once
#include "Cannonball.h"
#include "Ship.h"
#include <SFML/Graphics.hpp>

class Update
{
public:
	Update(){sf::RenderWindow window(sf::VideoMode(1200, 800), "jottain muuta!" );};
	~Update(void);

	void GameUpdate();

	void Collision();

	void Input(std::vector<Ship>::iterator si);

	sf::RenderWindow GetWindow();

private:

	sf::RenderWindow window;
	sf::Clock clock;
	sf::Time elapsed1;
	sf::Texture *tex;

	std::vector<Ship> shipvector;
	std::vector<Cannonball*> ballvector;

	std::vector<Ship>::iterator si;
	std::vector<Cannonball*>::iterator ci;
};


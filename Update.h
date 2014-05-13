#pragma once
#include "Cannonball.h"
#include "Ship.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class Update
{
public:

	Update(sf::RenderWindow & window);
	//~Update(void);

	int GameUpdate(sf::RenderWindow & window);

	bool Collision();

	void Input(std::vector<Ship*>::iterator si);

	void ShipGraphicUpdate();

	static std::vector<Ship*> shipvector;
	static std::vector<Ship*>::iterator si;



	sf::RenderWindow & window;

	

protected:

	std::vector<Cannonball*>::iterator ci;
	std::vector<Cannonball*> ballvector;

	
	std::vector<GO> GOvector;
	std::vector<GO>::iterator gi;
	
	std::vector<GO> GOIvector;
	std::vector<GO>::iterator gii;

	std::vector<Button*> cloudvector;
	std::vector<Button*>::iterator cloi;

	sf::Clock clock;
	sf::Time elapsed1;
	sf::Texture *tex;
	sf::Texture texturesheet;
	
	int loseCounter;
	float loadingTimer;
	float loadingTimerx;
	float spawnTimer, spawnTimerc;
	bool loading;
	bool loadingx;
	int laivaLKM, voittaja;

	sf::Event _event;

};


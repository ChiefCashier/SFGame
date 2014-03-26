#include "Game.h"



Game::Game(void)
{
	bool isRunning = true;
}


Game::~Game(void)
{}

void Game::GameLoop()
{
	

	Ship s(200, 300, tex, 0.0f, sf::IntRect(0, 0, 100, 100), 1);
	Ship k(400, 600, tex, 0.0f, sf::IntRect(0, 0, 100, 100), 2);

	shipvector.push_back(s);
	shipvector.push_back(k);


	while(U.GetWindow().isOpen())
	{
		U.GameUpdate();
	}



}
#include "Game.h"


sf::Texture* Game::tex;
Game::Game(void)
{
	
}


Game::~Game(void)
{}

void Game::GameLoop()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "jottain muuta!" );
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
	tex = &texturesheet;
	
	Ship s(200, 300, tex, 0.0f, sf::IntRect(0, 0, 100, 100), 1, 3);
	Ship k(400, 600, tex, 0.0f, sf::IntRect(100, 0, 100, 100), 2, 3);

	Update::shipvector.push_back(s);
	Update::shipvector.push_back(k);

	Update U(window);
	
	
	

	while(window.isOpen())
	{


		U.GameUpdate(window);


	}



}
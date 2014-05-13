#pragma once
#include <SFML/Graphics.hpp>

class VictoryScreen
{
public:
	VictoryScreen(sf::RenderWindow &window);
	~VictoryScreen(void);

	sf::RenderWindow & window;

	void VictoryScreenUpdate(sf::RenderWindow &window, int voittaja);

private:

	bool shape;
	int voittaja;

	sf::Texture *tex;
	sf::Texture texturesheet;
	sf::Text text;
	sf::Font font;
};
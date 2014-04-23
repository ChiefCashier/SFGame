#pragma once
#include <SFML/Graphics.hpp>

class VictoryScreen
{
public:
	VictoryScreen(sf::RenderWindow &window);
	~VictoryScreen(void);

	sf::RenderWindow & window;

	void VictoryScreenUpdate(sf::RenderWindow &window);

private:

	bool shape;

	sf::Texture *tex;
	sf::Texture texturesheet;
};
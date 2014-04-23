#include "VictoryScreen.h"

VictoryScreen::VictoryScreen(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}

VictoryScreen::~VictoryScreen(void)
{
}

void VictoryScreen::VictoryScreenUpdate(sf::RenderWindow &window)
{	while(window.isOpen())
	{
		window.clear(sf::Color::Red);
		//kaikki draw
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
}
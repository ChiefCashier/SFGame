#include "Mainmenu.h"


Mainmenu::Mainmenu(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}

Mainmenu::~Mainmenu(void)
{
}

void Mainmenu::MenuUpdate(sf::RenderWindow &window)
{
	while(shape != 1)
	{
		window.clear(sf::Color::Yellow);
		//kaikki Draw !!

		//GO button(600, 400, tex);

		window.display();














	}
}
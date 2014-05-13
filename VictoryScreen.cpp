#include "VictoryScreen.h"
#include "GO.h"

VictoryScreen::VictoryScreen(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM T�H�N TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}

VictoryScreen::~VictoryScreen(void)
{
}


void VictoryScreen::VictoryScreenUpdate(sf::RenderWindow &window, int v)
{	
	while(window.isOpen())
	{
		window.clear(sf::Color::Red);
		//kaikki draw

		
		if(!font.loadFromFile("GARAIT.ttf"))
			system("pause");


		
		text.setFont(font);
		text.setString("Voittaja");
		text.setCharacterSize(50);
		text.setColor(sf::Color::Blue);

		
		//text.setStyle(sf::Text::Bold  /*sf::Text::Underlined*/);

		text.setPosition(400, 350);

		// inside the main loop, between window.clear() and window.display()
		window.draw(text);
		GO sh�p(475, 550, tex, sf::IntRect(0, 117*v -117, 50, 117));
		sh�p.Rotate(-90);
		sh�p.Scale(2);
		sh�p.Draw(window);
		
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
}
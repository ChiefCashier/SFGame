#include "Mainmenu.h"
#include <iostream>

Mainmenu::Mainmenu(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}

Mainmenu::~Mainmenu(void)
{
}

int Mainmenu::MenuUpdate(sf::RenderWindow &window)
{
	GO button1(600.0f, 400.0f, tex, sf::IntRect(0, 0, 200, 100));
	GO button2(600.0f, 800.0f, tex, sf::IntRect(0, 0, 200, 100));
	laivaLKM = 2;
	while(shape)
	{


		window.clear(sf::Color::Yellow);
		//kaikki Draw !!
		button1.Draw(window);
		button2.Draw(window);
		
		window.display();

		
		std::cout << "mouse x: " << sf::Mouse::getPosition().x << std::endl;
		std::cout << "mouse y: " << sf::Mouse::getPosition().y << std::endl;

		
		if(sf::Mouse::getPosition().x > button1.Border().left &&
			sf::Mouse::getPosition().y > button1.Border().top &&
			sf::Mouse::getPosition().x < button1.Border().left + button1.Border().width &&
			sf::Mouse::getPosition().y < button1.Border().top + button1.Border().height)
			{
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					shape = false;
				}
			}

		if(sf::Mouse::getPosition().x > button2.Border().left &&
			sf::Mouse::getPosition().y > button2.Border().top &&
			sf::Mouse::getPosition().x < button2.Border().left + button2.Border().width &&
			sf::Mouse::getPosition().y < button2.Border().top + button2.Border().height)
			{
				window.pollEvent(_event);
				if(_event.type == sf::Event::MouseButtonReleased)
				{
					std::cout << "painallus "<< std::endl;
					if(_event.key.code == sf::Mouse::Left)
					{
						laivaLKM++;
							button2.Teejotaingo(sf::IntRect(0, 0, 100, 100));
						if(laivaLKM == 3)
							button2.Teejotaingo(sf::IntRect(0, 100, 100, 100));
						if(laivaLKM == 4)
							button2.Teejotaingo(sf::IntRect(0, 100, 100, 100));
						if(laivaLKM > 4)
						{
							button2.Teejotaingo(sf::IntRect(0, 0, 200, 100));
							laivaLKM = 1;
						}
					}
				}
			}
			


		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		shape = true;
		//window.close();
	}


	}
	return laivaLKM;
}
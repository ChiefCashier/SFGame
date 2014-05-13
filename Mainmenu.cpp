#include "Mainmenu.h"
#include <iostream>

Mainmenu::Mainmenu(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM. TÄHÄN TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}

Mainmenu::~Mainmenu(void)
{
}

int Mainmenu::MenuUpdate(sf::RenderWindow &window)
{
	GO button1(300.0f, 200.0f, tex, sf::IntRect(100, 200, 200, 100));
	GO button2(300.0f, 600.0f, tex, sf::IntRect(100, 200, 200, 100));
	GO laiva(800, 300, tex, sf::IntRect(0, 0, 50, 116));
	GO laiva2(1400, 300, tex, sf::IntRect(0, 116, 50, 116));
	GO laiva3(800, 700, tex,sf::IntRect(0, 0, 50, 116));
	GO laiva4(1400, 700, tex,sf::IntRect(0, 0, 50, 116));
	laivaLKM = 2;
	
	if(!font.loadFromFile("GARAIT.ttf"))
		system("pause");


		
	text.setFont(font);
	text.setString("START");
	text.setCharacterSize(50);
	text.setColor(sf::Color::Blue);
	text.setPosition(225, 165);

	text2.setFont(font);
	text2.setString("2");
	text2.setCharacterSize(50);
	text2.setColor(sf::Color::Blue);
	text2.setPosition(285, 565);

	while(shape)
	{


		window.clear(sf::Color::Yellow);
		//kaikki Draw !!
		button1.Draw(window);
		button2.Draw(window);
		window.draw(text);
		window.draw(text2);
		laiva.Draw(window);
		laiva2.Draw(window);
		if(laivaLKM == 3 || laivaLKM > 3)
			laiva3.Draw(window);
		if(laivaLKM == 4)
			laiva4.Draw(window);
		window.display();

		
		if(sf::Mouse::getPosition().x > button1.Border().left &&
			sf::Mouse::getPosition().y > button1.Border().top &&
			sf::Mouse::getPosition().x < button1.Border().left + button1.Border().width &&
			sf::Mouse::getPosition().y < button1.Border().top + button1.Border().height)
			{
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "mouse x: " << sf::Mouse::getPosition().x << std::endl;
					std::cout << "mouse y: " << sf::Mouse::getPosition().y << std::endl;
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
					std::cout << "mouse x: " << sf::Mouse::getPosition().x << std::endl;
					std::cout << "mouse y: " << sf::Mouse::getPosition().y << std::endl;
					std::cout << "painallus "<< std::endl;
					if(_event.key.code == sf::Mouse::Left)
					{
						laivaLKM++;
							
						if(laivaLKM == 3)
						{
							text2.setString("3");
							
						}
						if(laivaLKM == 4)
						{
							text2.setString("4");
							
						}
						if(laivaLKM > 4)
						{
							text2.setString("2");
							laivaLKM = 2;
						}
					}
				}
			}
			


		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		shape = true;
		window.close();
	}


	}
	return laivaLKM;
}
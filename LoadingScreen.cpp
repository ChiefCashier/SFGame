#include "LoadingScreen.h"


LoadingScreen::LoadingScreen(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}

LoadingScreen::~LoadingScreen(void)
{
}
void LoadingScreen::Update(sf::RenderWindow &window, int v)
{	
	float frameTime = 0;
	bool i = 0;

	while(i == 0)
	{
		
		window.clear(sf::Color::Black);
		//kaikki draw

		//sf::VertexArray trianglestrip(sf::TrianglesStrip, 6);


		//trianglestrip[0].position = sf::Vector2f(600, 15);
		//trianglestrip[1].position = sf::Vector2f(570, 495);
		//trianglestrip[2].position = sf::Vector2f(600, 505);
		//trianglestrip[3].position = sf::Vector2f(585, 500);
		//trianglestrip[4].position = sf::Vector2f(615, 510);
		//trianglestrip[5].position = sf::Vector2f(600, 1000);

		//trianglestrip[0].color = sf::Color::Red;
		//trianglestrip[1].color = sf::Color::Blue;
		//trianglestrip[2].color = sf::Color::Green;
		//trianglestrip[3].color = sf::Color::Green;
		//trianglestrip[4].color = sf::Color::Blue;
		//trianglestrip[5].color = sf::Color::Red;

		//window.draw(trianglestrip);


		font.loadFromFile("GARAIT.ttf");
		elapsed1 = clock.getElapsedTime();
		frameTime += elapsed1.asSeconds();
		clock.restart();

		text.setFont(font);
		text.setString("Press eny key to continue");
		text.setCharacterSize(100);
		text.setColor(sf::Color(255,255,255, 255 - frameTime * 200));
			if(text.getColor() == sf::Color(255, 255, 255, 0))
				text.setColor(sf::Color(255,255,255, +frameTime));
		
		text.setPosition(400, 350);
		window.draw(text);

		window.display();
		while (window.pollEvent(_event))
			if(_event.type == sf::Event::KeyPressed)
			{
				i = 1;
			}
	}
}

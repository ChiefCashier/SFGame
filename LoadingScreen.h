#pragma once
#include  <SFML/Graphics.hpp>
class LoadingScreen
{
public:
	LoadingScreen(sf::RenderWindow &window);
	~LoadingScreen(void);

	sf::RenderWindow & window;

	void Update(sf::RenderWindow &window, int laivalkm);

private:
	sf::Texture *tex;
	sf::Texture texturesheet;
	sf::Text text;
	sf::Font font;
	sf::Time elapsed1;
	sf::Clock clock;

	int laivaLKM;
	sf::Event _event;
};


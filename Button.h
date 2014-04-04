#pragma once
#include "GO.h"
class Button
{
public:
	Button(float x, float y, sf::Texture* tex, sf::IntRect border);
	~Button(void);
	void Draw(sf::RenderWindow & window);
	void setPosition();

private:

	float xPos, yPos;
	sf::Sprite  sprite;
	sf::IntRect border;

};


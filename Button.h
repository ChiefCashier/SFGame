#pragma once
#include "GO.h"
class Button
{
public:
	Button(float x, float y, sf::Texture* tex, sf::IntRect border, int);
	~Button(void);
	void Draw(sf::RenderWindow & window);
	void setPosition();
	void Move(float Frametime);
	sf::FloatRect Border();
	void Teejotain(sf::IntRect b);

private:

	float xPos, yPos;
	int speed;
	sf::Sprite  sprite;
	sf::IntRect border;
	sf::FloatRect Bord;
};


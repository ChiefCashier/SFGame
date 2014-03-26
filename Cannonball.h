#pragma once
#include "GO.h"

class Cannonball :public GO
{
public:

	Cannonball(float xPos, float yPos, sf::Texture* tex, float rotation, sf::IntRect border);
	void Draw(sf::RenderWindow & window);
	void SetPosition(float xPos ,float yPos);
	void Move();
	void SetRotation(float rotation);
	~Cannonball(void);

	sf::IntRect border;

private:

	float xPos, yPos;
	float rotation;
	sf::Sprite sprite;
	
};


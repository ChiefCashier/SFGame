#pragma once
#include "GO.h"
class Ship : public GO
{
public:

	Ship(float xPos, float yPos, sf::Texture* tex, float rotation, sf::IntRect border, int ID);
	~Ship(void);
	void Draw(sf::RenderWindow & window);
	void SetPosition(float xPos ,float yPos);
	float GetRotation();
	float GetPosx();
	float GetPosy();
	void Rotate(float r);
	void Move();
	int ID;

	sf::IntRect border;

private:
	float rotation;
	float xPos, yPos;
	
	sf::Sprite  sprite;
};


#pragma once
#include "go.h"
class Ship : public GO
{
public:

	Ship(float xPos, float yPos, sf::Texture* tex, float rotation, sf::IntRect border);
	~Ship(void);
	void Draw(sf::RenderWindow & window);
	void SetPosition(float xPos ,float yPos);
	float GetRotation();
	void Rotate(float r);
	void Move();

private:
	float rotation;
	float xPos, yPos;
	sf::Sprite  sprite;
};


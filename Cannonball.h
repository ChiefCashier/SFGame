#pragma once
#include "GO.h"

class Cannonball :public virtual GO
{
public:

	Cannonball(float xPos, float yPos, sf::Texture* tex, float rotation, sf::IntRect border, int ID);
	void Draw(sf::RenderWindow & window);
	void SetPosition(float xPos ,float yPos);
	void Move();
	void SetRotation(float rotation);
	int GetID();
	~Cannonball(void);
	sf::FloatRect Border();
	

private:

	float xPos, yPos;
	float rotation;
	sf::Sprite sprite;
	int ID;
	sf::IntRect border;
	sf::FloatRect Bord;
};


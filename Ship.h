#pragma once
#include "GO.h"
class Ship : public virtual GO
{
public:

	Ship(float xPos, float yPos, sf::Texture* tex, float rotation, sf::IntRect border, int ID, int Hp);
	~Ship(void);
	void Draw(sf::RenderWindow & window);
	void SetPosition(float xPos ,float yPos);
	float GetRotation();
	float GetPosx();
	float GetPosy();
	void Rotate(float r);
	void Move();
	int GetID();
	int GetHP();
	void SetHP(int);

	sf::FloatRect Border();
	
	
protected:

	float rotation;
	float xPos, yPos;
	int ID, Hp;
	sf::Sprite  sprite;
	float scale;
	sf::FloatRect border;
};


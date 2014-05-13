#pragma once
#include "GO.h"
class Ship : public virtual GO
{
public:

	Ship(float xPos, float yPos, sf::Texture* tex, float rotation, sf::IntRect border, int ID, float Hp);
	~Ship(void);
	void Draw(sf::RenderWindow & window);
	void SetPosition(float xPos ,float yPos);
	float GetRotation();
	float GetPosx();
	float GetPosy();
	void Rotate(float r);
	void Move(float frametime);
	void Move(float, float);
	int GetID();
	float GetHP();
	sf::Vector2f GetSpeed(float frametime);
	void SetHP(float x);

	sf::FloatRect Border();
	void Teejotain(sf::IntRect border);// vaihtaa spriten paikkaa 
	
protected:

	float rotation;
	float xPos, yPos;
	int ID, Hp;
	sf::Sprite  sprite;
	float scale;
	sf::FloatRect border;
};


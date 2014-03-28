#include "Ship.h"


Ship::Ship(float x, float y, sf::Texture* tex, float r, sf::IntRect border, int id)
{
	xPos = x;
	yPos = y;
	rotation = r;
	sprite.setTexture(*tex);
	sprite.setTextureRect(border);
	sprite.setPosition(x, y);
	sprite.setOrigin(50, 50);
	
	ID = id;
}

Ship::~Ship(void)
{
}

void Ship::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Ship::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Ship::Rotate(float rotation)
{
	sprite.rotate(rotation);
}

float Ship::GetRotation()
{
	return sprite.getRotation();
}

void Ship::Move()
{
	sprite.move(-0.0004*sin(rotation*3.14159265/180), 0.0004*cos(rotation*3.14159265/180));
}

float Ship::GetPosx()
{
	return sprite.getPosition().x;
}

float Ship::GetPosy()
{
	return sprite.getPosition().y;
}
int Ship::GetID()
{ 
	return ID;
}
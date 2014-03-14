#include "Ship.h"


Ship::Ship(float x, float y, sf::Texture* tex, float r, sf::IntRect border)
{
	xPos = x;
	yPos = y;
	rotation = r;
	sprite.setTexture(*tex);
	sprite.setTextureRect(border);
	sprite.setPosition(x, y);
}

Ship::~Ship(void)
{
}

void Ship::Draw(sf::RenderWindow & window)
{

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
	sprite.move(-4*sin(rotation*3.14159265/180), 4*cos(rotation*3.14159265/180));
}
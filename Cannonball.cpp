#include "Cannonball.h"


Cannonball::Cannonball(float x, float y, sf::Texture* tex, float r, sf::IntRect border)
{
	xPos = x;
	yPos = y;
	rotation = r;
	sprite.setTexture(*tex);
	sprite.setTextureRect(border);
	sprite.setPosition(x, y);
}

Cannonball::~Cannonball(void)
{
}

void Cannonball::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Cannonball::SetPosition(float x ,float y)
{
	sprite.setPosition(x, y);
}

void Cannonball::Move()
{
	sprite.move(-40*sin(rotation*3.14159265/180), 40*cos(rotation*3.14159265/180));
}

void Cannonball::SetRotation(float rotation)
{
	sprite.setRotation(rotation);
}
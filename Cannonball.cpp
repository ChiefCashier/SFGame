#include "Cannonball.h"


Cannonball::Cannonball(float x, float y, sf::Texture* tex, float r, sf::IntRect border, int id)
{
	xPos = x;
	yPos = y;
	rotation = r;
	sprite.setTexture(*tex);
	sprite.setTextureRect(border);
	sprite.setPosition(x, y);
	sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
	ID = id;
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
	sprite.move(-4*sin(rotation*3.14159265/180), 4*cos(rotation*3.14159265/180));
	sprite.setRotation(rotation);
}

void Cannonball::SetRotation(float rotation)
{
	sprite.setRotation(rotation);
}

int Cannonball::GetID()
{
	return ID;
}
sf::FloatRect Cannonball::Border()
{
	Bord = sprite.getGlobalBounds();
	
	return Bord;
}
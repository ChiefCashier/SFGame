#include "Cannonball.h"


Cannonball::Cannonball(float x, float y, sf::Texture* tex, float r, sf::IntRect border, int id, sf::Vector2f s)
{
	xPos = x;
	yPos = y;
	rotation = r;
	sprite.setTexture(*tex);
	sprite.setTextureRect(border);
	sprite.setPosition(x, y);
	sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
	ID = id;
	speed = s;
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

void Cannonball::Move(float Frametime)
{
	sprite.move((-450*sin(rotation*3.14159265/180)+ speed.x) * Frametime , (450*cos(rotation*3.14159265/180) + speed.y)* Frametime );
	sprite.setRotation(rotation *1.5);
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
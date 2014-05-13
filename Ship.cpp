#include "Ship.h"


Ship::Ship(float x, float y, sf::Texture* tex, float r, sf::IntRect border, int id, float HP)
{
	xPos = x;
	yPos = y;
	rotation = r;
	sprite.setTexture(*tex);
	sprite.setTextureRect(border);
	sprite.setPosition(x, y);
	sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
	ID = id;
	Hp = HP;
	scale = 50; // prosenttia spriten koosta
	scale = 100-scale;
	scale *= 0.005;
	
}
GO::GO()
{
	xPos = 0;
	yPos = 0;
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

void Ship::Move(float frametime)
{
	sprite.move(-400 * sin(sprite.getRotation()*3.14159265/180)*frametime, 400*cos(sprite.getRotation()*3.14159265/180)*frametime);
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
sf::FloatRect Ship::Border()
{
	//sf::FloatRect asd(
	//	sprite.getOrigin().x-((sprite.getGlobalBounds().width)*0.50),
	//	sprite.getOrigin().y-((sprite.getGlobalBounds().height)*0.50),
	//	(sprite.getGlobalBounds().width)*0.75,
	//	(sprite.getGlobalBounds().height)*0.75);

	border.top = sprite.getGlobalBounds().top + (sprite.getLocalBounds().height * scale);
	border.left = sprite.getGlobalBounds().left + (sprite.getLocalBounds().width * scale);
	border.height = sprite.getGlobalBounds().height - (sprite.getLocalBounds().height * scale * 2);
	border.width = sprite.getGlobalBounds().width - (sprite.getLocalBounds().width * scale * 2);


	return border;
}

float Ship::GetHP()
{
	return Hp;
}

void Ship::SetHP(float x)
{
	Hp = x;
}

void Ship::Teejotain(sf::IntRect b)
{
	sprite.setTextureRect(b);
}

sf::Vector2f Ship::GetSpeed(float frametime)
{
	return	sf::Vector2f(-400*sin(sprite.getRotation()*3.14159265/180) * frametime, 400*cos(sprite.getRotation()*3.14159265/180)* frametime);
}
void Ship::Move(float xs, float ys)
{
	sprite.move(xs, ys);
}
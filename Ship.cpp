#include "Ship.h"


Ship::Ship(float x, float y, sf::Texture* tex, float r, sf::IntRect border, int id, int HP)
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
	scale = 75; // prosenttia spriten koosta
	scale = 100-scale;
	scale *= 0.005;
	
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
	sprite.move(-0.04*sin(sprite.getRotation()*3.14159265/180)*0, 0*0.04*cos(sprite.getRotation()*3.14159265/180));
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

int Ship::GetHP()
{
	return Hp;
}

void Ship::SetHP(int x)
{
	Hp = x;
}
#include "Button.h"


Button::Button(float x, float y, sf::Texture* tex, sf::IntRect border, int s)
{
	xPos = x;
	yPos = y;
	sprite.setTexture(*tex);
	sprite.setPosition(xPos, yPos);
	sprite.setTextureRect(border);
	sprite.setColor(sf::Color(255, 255, 255, 125));
	speed = s;
}


Button::~Button(void)
{
}

void Button::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Button::setPosition()
{
	sprite.setPosition(xPos, yPos);
	sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
}

void Button::Teejotain(sf::IntRect b)
{
	sprite.setTextureRect(b);
}

void Button::Move(float Frametime)
{
	sprite.move(-speed * Frametime, 0);
}

sf::FloatRect Button::Border()
{
	Bord = sprite.getGlobalBounds();
	
	return Bord;
}
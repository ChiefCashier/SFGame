#include "GO.h"


GO::GO(float x, float y, sf::Texture* tex)
{
	xPos = x;
	yPos = y;
	sprite.setTexture(*tex);
	sprite.setPosition(xPos, yPos);

}
GO::GO()
{
	xPos = 0;
	yPos = 0;
}
GO::~GO(void)
{
}

void GO::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void GO::setPosition()
{
	sprite.setPosition(xPos, yPos);
	sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);
}

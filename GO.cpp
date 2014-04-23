#include "GO.h"


GO::GO(float x, float y, sf::Texture* tex, sf::IntRect border)
{
	xPos = x;
	yPos = y;
	sprite.setTexture(*tex);
	sprite.setPosition(xPos, yPos);
	sprite.setTextureRect(border);
	sprite.setOrigin((sprite.getLocalBounds().width)/2, (sprite.getLocalBounds().height)/2);


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

}

sf::FloatRect GO::Border()
{
	return sprite.getGlobalBounds();
}


void GO::Teejotaingo(sf::IntRect b)
{
	sprite.setTextureRect(b);
}

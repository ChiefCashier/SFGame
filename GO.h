#pragma once
#include <SFML/Graphics.hpp>


class GO
{
public:
	GO(float xPos, float yPos, sf::Texture* tex, sf::IntRect border);
	GO();
	~GO(void);
	virtual void Draw(sf::RenderWindow & window);
	virtual void setPosition();
	sf::FloatRect Border();
	virtual void Teejotaingo(sf::IntRect);

private:

	float xPos, yPos;
	sf::Sprite  sprite;
	
};

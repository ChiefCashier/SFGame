#pragma once
#include <SFML/Graphics.hpp>


class GO
{
public:
	GO(float xPos, float yPos, sf::Texture* tex);
	GO();
	~GO(void);
	void virtual Draw(sf::RenderWindow & window);
	void virtual setPosition();

private:

	float xPos, yPos;
	sf::Sprite  sprite;

};

#pragma once
#include <SFML/Graphics.hpp>


class GO
{
public:
	GO(float xPos, float yPos, sf::Texture* tex, sf::IntRect border);
	GO(float xPos, float yPos, sf::Texture* tex, sf::IntRect border, int ID);
	GO();
	~GO(void);
	virtual void Draw(sf::RenderWindow & window);
	virtual void SetPosition(int x, int y);
	void Rotate(int x);
	sf::FloatRect Border();
	int GetID();
	virtual void Teejotaingo(sf::IntRect);
	void Scale(int i);

private:

	float xPos, yPos;
	int ID;
	sf::Sprite  sprite;
	
};

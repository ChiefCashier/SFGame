#include "Input.h"
#include <SFML/Graphics.hpp>

Input::Input(void)
{
}


Input::~Input(void)
{
}

int Input::GetInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return 4;

       

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		return 5;	
	else
		return 0;

}
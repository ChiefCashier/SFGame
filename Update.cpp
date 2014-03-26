#include "Update.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

//Update::Update(void)
//{
//	
//}
//
//
//Update::~Update(void)
//{
//}

void Update::GameUpdate()
{
		
	elapsed1 = clock.getElapsedTime();
	clock.restart();

	window.clear(sf::Color::Blue);
		
	for( si = shipvector.begin(); si != shipvector.end() ; si++)	
		si->Draw(window);
	for( ci = ballvector.begin(); ci != ballvector.end() ; ci++)
		(*ci)->Draw(window);

	window.display();


	for( si = shipvector.begin(); si != shipvector.end() ; si++)
		Input(si);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();

	Collision();

	for( si = shipvector.begin(); si != shipvector.end() ; si++)
		si->Move();
	for( ci = ballvector.begin(); ci != ballvector.end() ; ci++)
		(*ci)->Move();


	



	
}

void Update::Collision()
{
	for(si = shipvector.begin(); si != shipvector.end();)
	{
		for(ci = ballvector.begin(); ci != ballvector.end();)
					{
					
						if(!si->border.intersects( ((*ci)->border)))
							ci++;
						else
						{
							(*ci)->~Cannonball();
							ci = ballvector.erase(ci);
						
						}
					
					}
		si++;
	}

}

void Update::Input(std::vector<Ship>::iterator si)
{
	float frameTime = elapsed1.asSeconds();
	cout << frameTime << endl;

	if(si->ID == 1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        si->Rotate(-150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		si->Rotate(+150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			ballvector.push_back(new Cannonball(si->GetPosx(), si->GetPosy(), tex,  si->GetRotation()-90, sf::IntRect(0, 0, 100, 100)));
		
	}

	if(si->ID == 2)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		si->Rotate(-150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		si->Rotate(+150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			ballvector.push_back(new Cannonball(si->GetPosx(), si->GetPosy(), tex,  si->GetRotation()-90, sf::IntRect(0, 0, 100, 100)));
	}

}
sf::RenderWindow Update::GetWindow()
{
	return window;

}
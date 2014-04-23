#include "Update.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

vector<Ship*> Update::shipvector;
vector<Ship*>::iterator Update::si;
Update::Update(sf::RenderWindow &window)
	:window(window)
{
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
				tex = &texturesheet;
}


//Update::~Update(void)
//{
//}

void Update::GameUpdate(sf::RenderWindow & window)
{
	loseCounter = 0;
	while(Collision() && window.isOpen())
	{


	elapsed1 = clock.getElapsedTime();
	clock.restart();

	window.clear(sf::Color::Blue);
		

	for( ci = ballvector.begin(); ci != ballvector.end() ; )
	{
		if((*ci)->Border().intersects(sf::FloatRect(0, 0, 1920, 1200)))
		{
			(*ci)->Draw(window);
			ci++;
		}
		else
		{
			(*ci)->~Cannonball();
			ci = ballvector.erase(ci);//tässä tuhotaan bulletit
		}
	}
	
	for( si = shipvector.begin(); si != shipvector.end() ; si++)	
		(*si)->Draw(window);
	window.display();
	
	for( si = shipvector.begin(); si != shipvector.end() ; si++)
		Input(si);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();

	float frameTime = elapsed1.asSeconds();

	for( si = shipvector.begin(); si != shipvector.end() ; si++)
		(*si)->Move(frameTime);
	for( ci = ballvector.begin(); ci != ballvector.end() ; ci++)
		(*ci)->Move();


	


	}
	
}

bool Update::Collision()
{
	for(si = shipvector.begin(); si != shipvector.end();)
	{
		for(ci = ballvector.begin(); ci != ballvector.end();)
		{
			
			if(!((*si)->Border()).intersects( (*ci)->Border() ) )
			{
				ci++;
			}
			else
			{
				if((*ci)->GetID() == (*si)->GetID())
				{
					ci++;
				}
				else
				{
					(*ci)->~Cannonball();
					ci = ballvector.erase(ci);
					(*si)->SetHP(((*si)->GetHP())-1);

					if((*si)->GetHP() == 0)
					{
						(*si)->SetPosition(-1000,-1000);
						// kumpi laiva voitti !!!!
						// victory screen asd
						// asioita tapahtuu asdasda
						loseCounter++;
						if(1 == (2 - loseCounter))
						{
							return false;
						}
					}


				}
			}	
			
			
			
		}

		si++;
	}
	return true;
}

void Update::Input(std::vector<Ship*>::iterator si)//tarvitsee vielä lataus systeemin;
{
	
	float frameTime = elapsed1.asSeconds();
	cout << frameTime << endl;

		if((*si)->GetID() == 2)
		{
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		(*si)->Rotate(-150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		(*si)->Rotate(+150*frameTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()-90, sf::IntRect(0, 100, 50, 50), (*si)->GetID()));
			}//lisää mahdollisuuksia ampua!!!
		}
	
			if((*si)->GetID() == 1)
		{

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		(*si)->Rotate(-150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		(*si)->Rotate(+150*frameTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				(*si)->Teejotain(sf::IntRect(0, 0, 200, 100));
			}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()-90, sf::IntRect(0, 100, 50, 50), (*si)->GetID()));
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				
				ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()+90, sf::IntRect(0, 100, 50, 50), (*si)->GetID()));
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				
				ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation(), sf::IntRect(0, 100, 50, 50), (*si)->GetID()));
			}
		}

}

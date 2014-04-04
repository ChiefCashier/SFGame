#include "Update.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

vector<Ship> Update::shipvector;
vector<Ship>::iterator Update::si;
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
		
	elapsed1 = clock.getElapsedTime();
	clock.restart();

	window.clear(sf::Color::Blue);
		

	for( ci = ballvector.begin(); ci != ballvector.end() ; )
	{
		if((*ci)->Border().intersects(sf::FloatRect(0, 0, 1200, 800)))
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
		si->Draw(window);
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
			
			if(!(si->Border()).intersects( (*ci)->Border() ) )
			{
				ci++;
			}
			else
			{
				if((*ci)->GetID() == si->GetID())
				{
					ci++;
				}
				else
				{
					(*ci)->~Cannonball();
					ci = ballvector.erase(ci);
					si->SetHP((si->GetHP())-1);

					if(si->GetHP() == 0)
					{
						// kumpi laiva voitti !!!!
						// victory screen asd
						// asioita tapahtuu asdasda
					}
				}
			}	
			
			
			
		}
		si++;
	}
		
}

void Update::Input(std::vector<Ship>::iterator si)//tarvitsee vielä lataus systeemin;
{
	
	float frameTime = elapsed1.asSeconds();
	cout << frameTime << endl;

		if(si->GetID() == 2)
		{
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		si->Rotate(-150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		si->Rotate(+150*frameTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				ballvector.push_back(new Cannonball(si->GetPosx(), si->GetPosy(), tex,  si->GetRotation()-90, sf::IntRect(0, 100, 50, 50), si->GetID()));
			}//lisää mahdollisuuksia ampua!!!
		}
	
			if(si->GetID() == 1)
		{

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		si->Rotate(-150*frameTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		si->Rotate(+150*frameTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				
				ballvector.push_back(new Cannonball(si->GetPosx(), si->GetPosy(), tex,  si->GetRotation()-90, sf::IntRect(0, 100, 50, 50), si->GetID()));
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				
				ballvector.push_back(new Cannonball(si->GetPosx(), si->GetPosy(), tex,  si->GetRotation()+90, sf::IntRect(0, 100, 50, 50), si->GetID()));
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				
				ballvector.push_back(new Cannonball(si->GetPosx(), si->GetPosy(), tex,  si->GetRotation(), sf::IntRect(0, 100, 50, 50), si->GetID()));
			}
		}

}

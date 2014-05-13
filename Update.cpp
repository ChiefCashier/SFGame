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

int Update::GameUpdate(sf::RenderWindow & window)
{
	loseCounter = 0;
	voittaja = 0;
	for(si = shipvector.begin(); si != shipvector.end(); si++)
	{
		if((*si)->GetID() == 4)
		{
			(*si)->SetPosition(1200, 900);
			laivaLKM = 4;
			GO healthbar4((*si)->GetPosx(), (*si)->GetPosy(), tex, sf::IntRect(0, 450, 60, 5));
			GOvector.push_back(healthbar4);
		}
		else if((*si)->GetID() == 3)
		{
			(*si)->SetPosition(300, 900);
			laivaLKM = 3;
			GO healthbar3((*si)->GetPosx(), (*si)->GetPosy(), tex, sf::IntRect(0, 450, 60, 5));
			GOvector.push_back(healthbar3);
		}
		else if((*si)->GetID() == 2)
		{
			(*si)->SetPosition(1200, 300);
			laivaLKM = 2;
			GO healthbar2((*si)->GetPosx(), 100.0f, tex, sf::IntRect(0, 450, 60, 5));
			GOvector.push_back(healthbar2);
		}
		else if((*si)->GetID() == 1)
		{
			(*si)->SetPosition(300, 300);
			GO healthbar1((*si)->GetPosx(), (*si)->GetPosy() + 50, tex, sf::IntRect(0, 450, 60, 5));
			GOvector.push_back(healthbar1);
		}
		spawnTimer = 0;
		spawnTimerc = 0;
		loadingTimer = 0;
		loadingTimerx = 0;
		loading = true;
		loadingx = true;
		srand(time(NULL));
	}
	while(Collision() && window.isOpen())
	{


	elapsed1 = clock.getElapsedTime();
	clock.restart();

	window.clear(sf::Color::Blue);
	
	ShipGraphicUpdate();







	//piirto alkaa
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
			ci = ballvector.erase(ci);//tässä tuhotaan bulletit, jotka menevät ruudun ulkopuolelle
		}
	}

	



	

	for(gii = GOIvector.begin(); gii != GOIvector.end(); gii++)
		gii->Draw(window);

	for( si = shipvector.begin(); si != shipvector.end() ; si++)	
		(*si)->Draw(window);

	for(cloi = cloudvector.begin(); cloi != cloudvector.end();)
	{
		if((*cloi)->Border().intersects(sf::FloatRect(0, 0, 2020, 1200)))
		{
			(*cloi)->Draw(window);
			cloi++;
		}
		else
		{
			(*cloi)->~Button();
			cloi = cloudvector.erase(cloi);
		}
	}
	
	for( si = shipvector.begin(); si != shipvector.end() ; si++)
		Input(si);

	for(gi = GOvector.begin(); gi != GOvector.end(); gi++)
		gi->Draw(window);

	
	//piirto loppuu
	window.display();//esitys
	

	float frameTime = elapsed1.asSeconds();

	for( si = shipvector.begin(); si != shipvector.end() ; si++)
		(*si)->Move(frameTime);
	for( ci = ballvector.begin(); ci != ballvector.end() ; ci++)
		(*ci)->Move(frameTime);
	for( cloi = cloudvector.begin(); cloi != cloudvector.end() ; cloi++)
		(*cloi)->Move(frameTime);


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		while(_event.type != sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			while(window.pollEvent(_event))
			{
				if(_event.type == sf::Event::Closed)
				{
					window.close();
				}
				if(_event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
			

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				clock.restart();
				break;
			}

		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();


	
	while(window.pollEvent(_event))
		{
			if(_event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		spawnTimer += frameTime;
		spawnTimerc += frameTime;
		if(spawnTimerc > 2)
		{
			
			cloudvector.push_back(new Button(1940, (rand() % 1200), tex, sf::IntRect(400, 0, 100, 100),(rand() % 100 + 300)));
			
			spawnTimerc = 0;
		}
		if(spawnTimerc > 1)
			
		if(spawnTimer > 5)
			{	
				int x = rand() % 2;
				std::cout << x << std::endl;
				GO item(100*(rand() % 14+1), 100*(rand() % 9+1), tex, sf::IntRect(0, 100 * x + 200, 100, 100), x); //pickuppeja
				spawnTimer = 0;
				GOIvector.push_back(item);
				
			}
	}
	
	return voittaja;
}

bool Update::Collision()
{

	//Ship vs cannonball
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
					float hp = 0;
					hp = (*si)->GetHP() - 1;
					std::cout << hp << std::endl;
					(*si)->SetHP(hp);
					std::cout << (*si)->GetHP() << std::endl;
					std::cout << ballvector.capacity() << "   " <<  ballvector.size() << endl;

					GOvector.at( (*si)->GetID() - 1 ).Teejotaingo(sf::IntRect(0, 450, 5 * (*si)->GetHP(), 5));

					if((*si)->GetHP() == 0)
					{
						(*si)->SetPosition(-1000,-1000);
						// kumpi laiva voitti !!!! ei tiiä
						// victory screen asd
						// asioita tapahtuu asdasda
						loseCounter++;
						if(1 == (laivaLKM - loseCounter))
						{
							
							for(si = shipvector.begin(); si != shipvector.end(); si++)
								if((*si)->GetHP() > 0)
									voittaja = (*si)->GetID();

							return false;
						}
					}


				}
			}	
			
			
			
		}

		si++;
	}
	//Ship vs Item
	for(si = shipvector.begin(); si != shipvector.end();)
	{
		for(gii = GOIvector.begin(); gii != GOIvector.end();)
		{
			if(!((*si)->Border()).intersects( gii->Border() ) )
			{
				gii++;
			}
			else
			{
				
				if(gii->GetID() == 0)
				{
					(*si)->SetHP((*si)->GetHP() + 1);
					GOvector.at( (*si)->GetID() - 1 ).Teejotaingo(sf::IntRect(0, 450, 5 * (*si)->GetHP(), 5));
				}
				if(gii->GetID() == 1)
				{
					float frameTime = elapsed1.asSeconds();
					for(int i = 0 ; i < 10 ; i++)
						ballvector.push_back(
						new Cannonball((*si)->GetPosx() - (*si)->GetSpeed(frameTime).x * 0.1,
						(*si)->GetPosy() - (*si)->GetSpeed(frameTime).y * 0.1,
						tex,  36 * i, sf::IntRect(0, 400, 16, 16), 
						(*si)->GetID(),(*si)->GetSpeed(frameTime))
						);
				}
				gii = GOIvector.erase(gii);
			}

		}
		si++;
	}
	//ship vs wall
	for(si = shipvector.begin(); si != shipvector.end();)
	{
		if((*si)->Border().intersects(sf::FloatRect(0, 0, -10, 1200)))
			{	
				float frameTime = elapsed1.asSeconds();
				(*si)->Move(400 * sin((*si)->GetRotation()*3.14159265/180)*frameTime, 0);
			}
		if((*si)->Border().intersects(sf::FloatRect(0, 0, 1920, -10)))
			{	
				float frameTime = elapsed1.asSeconds();
				(*si)->Move(0, -400 * cos((*si)->GetRotation()*3.14159265/180) *frameTime);
			}
		if((*si)->Border().intersects(sf::FloatRect(1920, 0, -10, 1200)))
			{	
				float frameTime = elapsed1.asSeconds();
				(*si)->Move(400 * sin((*si)->GetRotation()*3.14159265/180)*frameTime, 0);
			}
		if((*si)->Border().intersects(sf::FloatRect(0, 1200, 1920, -10)))
			{	
				float frameTime = elapsed1.asSeconds();
				(*si)->Move(0, -400 * cos((*si)->GetRotation()*3.14159265/180)*frameTime);
			}
		si++;
	}



	return true;
}

void Update::Input(std::vector<Ship*>::iterator si)
{
	
	float frameTime = elapsed1.asSeconds();
	//cout << frameTime << endl;
	
	
	loadingTimer += frameTime;
	loadingTimerx += frameTime;
		
		if(loadingTimer > 0.9)
			{
				loadingTimer = 0;
				loading = false;
			}
		if(loadingTimerx > 0.9)
			{
				loadingTimerx = 0;
				loadingx = false;
			}
		if((*si)->GetID() == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			(*si)->Rotate(-150*frameTime);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			(*si)->Rotate(+150*frameTime);

			if(!loading)//latauksen tarkistus
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
					{
						(*si)->Teejotain(sf::IntRect(0, 0, 200, 100));
					}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
					{
						loading = true;
						loadingTimer = 0;
						cloudvector.push_back(new Button(
							(*si)->GetPosx(), 
							(*si)->GetPosy(), 
							tex, 
							sf::IntRect(400, 0, 100, 100), 
							rand() % 100 + 300)
							);
						ballvector.push_back(new Cannonball((*si)->GetPosx() + (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() + (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx() - (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() - (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					{
						loading = true;
						loadingTimer = 0;
						cloudvector.push_back(new Button(
							(*si)->GetPosx(), 
							(*si)->GetPosy(), 
							tex, 
							sf::IntRect(400, 0, 100, 100), 
							rand() % 100 + 300)
							);
						ballvector.push_back(new Cannonball((*si)->GetPosx() + (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() + (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx() - (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() - (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
				
			}
		}
		if((*si)->GetID() == 3)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
			(*si)->Rotate(-150*frameTime);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
			(*si)->Rotate(+150*frameTime);

			//if(!loading)//latauksen tarkistus
			{
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
					{
						//loading = true;
						//loadingTimer = 0;
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
					{
						//loading = true;
						//loadingTimer = 0;
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
					{
						//loading = true;
						//loadingTimer = 0;
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation(), sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
			}
		}
		
		if((*si)->GetID() == 2)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
			(*si)->Rotate(-150*frameTime);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
			(*si)->Rotate(+150*frameTime);

			if(!loadingx)//latauksen tarkistus
			{
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
					{
						loadingx = true;
						loadingTimerx = 0;
						cloudvector.push_back(new Button(
							(*si)->GetPosx(), 
							(*si)->GetPosy(), 
							tex, 
							sf::IntRect(400, 0, 100, 100), 
							rand() % 100 + 300)
							);


						ballvector.push_back(new Cannonball((*si)->GetPosx() + (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() + (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx() - (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() - (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()-90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
					{
						loadingx = true;
						loadingTimerx = 0;
						cloudvector.push_back(new Button(
							(*si)->GetPosx(), 
							(*si)->GetPosy(), 
							tex, 
							sf::IntRect(400, 0, 100, 100), 
							rand() % 100 + 300)
							);
						ballvector.push_back(new Cannonball((*si)->GetPosx() + (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() + (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx(), (*si)->GetPosy(), tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
						ballvector.push_back(new Cannonball((*si)->GetPosx() - (*si)->GetSpeed(frameTime).x * 0.1, (*si)->GetPosy() - (*si)->GetSpeed(frameTime).y * 0.1, tex,  (*si)->GetRotation()+90, sf::IntRect(0, 400, 16, 16), (*si)->GetID(), (*si)->GetSpeed(frameTime)));
					}
				
			}
			
		}
}
void Update::ShipGraphicUpdate()
{

	//poistettiin liian artistisen vaivan takia
	//olisi toimiessaan vaihtanut spriten rotaation mukaan spriten textuuria

	for(si = shipvector.begin(); si != shipvector.end(); si++)
	{	
		float r = 0;
		r = (*si)->GetRotation();

		//std::cout << r << std::endl;


		//if(r > 0 && r < 90)
		//{
		//	(*si)->Teejotain(sf::IntRect(0, ((*si)->GetID() - 1)*100, 100, 100)); 
		//}
		//if(r > 90 && r < 180)
		//{
		//	(*si)->Teejotain(sf::IntRect(100, ((*si)->GetID() - 1)*100, 100, 100));
		//}
		//if(r > 180 && r < 270)
		//{
		//	(*si)->Teejotain(sf::IntRect(200, ((*si)->GetID() - 1)*100, 100, 100));
		//}
		//if(r > 270 && r < 360)
		//{
		//	(*si)->Teejotain(sf::IntRect(300, ((*si)->GetID() - 1)*100, 100, 100));
		//}

		
		//std::cout <<"X: "<< (*si)->GetPosx() << " "<< "Y: "<< (*si)->GetPosy() << std::endl;
	}
	gi = GOvector.begin();
	si = shipvector.begin();
	for(int i = 0; i < 2; i++)
	{
		
		gi->SetPosition((*si)->GetPosx(), (*si)->GetPosy() + 100);
		si++;
		gi++;
	}

}
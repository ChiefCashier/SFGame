#include "Game.h"


sf::Texture* Game::tex;
Game::Game(void)
{
	
}


Game::~Game(void)
{}

void Game::GameLoop()
{
	sf::RenderWindow window(sf::VideoMode(std::min(sf::VideoMode::getDesktopMode().width,(unsigned)1920)//1920
                            , std::min(sf::VideoMode::getDesktopMode().height,(unsigned)1200))//1200
							,"jottain muuta!", sf::Style::None);
	texturesheet.loadFromFile("spreadsheet.png");// HUOM TÄHÄN TULEE TEXTUURIMAPPI!!!!!
	tex = &texturesheet;
	
	Mainmenu M(window);

	int laivaLKM = M.MenuUpdate(window);
	
	for(int i = 0; i < laivaLKM; i++)//dynaaminen laivan luonti, jossa mukana mahdollisuus laivojen lkm:n päättämiseen
	{
		Ship* ship = new Ship(0, 0,// x ja y kordinaatit
			tex, i*180 , //textuuri  ,  laivan rotaatio
			sf::IntRect(0, (i)*115 + 1, 50, 115), i+1, 4);//paikka textuureissa  ,  id  ,  health

		Update::shipvector.push_back(ship);
	}
	LoadingScreen LC(window);
	LC.Update(window, laivaLKM);

	Update U(window);

	int voittaja = U.GameUpdate(window);

	VictoryScreen VS(window);
	 
	VS.VictoryScreenUpdate(window, voittaja);
	



}
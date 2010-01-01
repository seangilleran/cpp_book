// Sean Gilleran
// Chapter 5 Game
// s_Game.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "s_Player.h"
#include "s_Map.h"
using namespace std;

int main()
{
	srand( time( 0 ) );
	Map gameMap;
	Player mainPlayer;

	cout << "Chapter 5 RPG" << endl;
	cout << "by Sean Gilleran" << endl;
	cout << endl;
	cout << "The land has been oppressed for far too long by the machinations" << endl;
	cout << "of the evil Black Knight; journey to his castle and defeat him!" << endl;
	cout << "There is much adventure to be had along the way... GOOD LUCK!" << endl;
	cout << endl;

	// Create the Character
	mainPlayer.createClass();

	bool done = false;
	while( !done )
	{
		int selection = 1;
		
		while( true )
		{
			if( gameMap.atHome() )
			{
				cout << "You are at home in your Castle." << endl;
			}
			else if( gameMap.atStore() )
			{
				cout << "You are at the village shop." << endl;
			}
			else if( gameMap.atBoss() )
			{
				cout << "You arrive at the castle of the Black Knight!" << endl;
				cout << "Beware..." << endl;
			}
			else
			{
				cout << "You are in the forest." << endl;
			}

			cout << "Select an Action:" << endl;
			cout << " 1)Move" << endl;
			cout << " 2)Rest" << endl;
			cout << " 3)View Stats" << endl;
			cout << " 4)Check Map" << endl;
			cout << " 5)Quit" << endl;
			std::cout << ">";
			cin >> selection;
			cout << endl;

			Monster *monster = 0;

			if( selection == 1 )
			{
				if( gameMap.movePlayer() && !gameMap.atHome() && !gameMap.atStore() && !gameMap.atBoss() )
					monster = gameMap.checkRandomEncounter( false );
				else
					monster = 0;

				// Combat
				if( monster != 0 )
				{
					while( true )
					{
						mainPlayer.displayHitPoints();
						monster->displayHitPoints();
						cout << endl;

						if( mainPlayer.attack( *monster ) )
						{
							int fleeing = Random( 4, 1 );
							
							if( fleeing == 1 )
								gameMap.forceMovePlayer( 1, 0 );
							else if( fleeing == 2 )
								gameMap.forceMovePlayer( -1, 0 );
							else if( fleeing == 3 )
								gameMap.forceMovePlayer( 0, 1 );
							else if( fleeing == 4 )
								gameMap.forceMovePlayer( 0, -1 );
							break;
						}

						if( monster->isDead() )
						{
							mainPlayer.victory( monster->getXPReward(), monster->getGPReward() );
							mainPlayer.levelUp();
							break;
						}

						monster->attack( mainPlayer );

						if( mainPlayer.isDead() )
						{
							mainPlayer.gameover();
							done = true;
							break;
						}
					}
				}

				delete monster;
				monster = 0;
				break;
			}
			else if( selection == 2 )
			{
				if( Random( 4, 1 ) == 1 && !gameMap.atHome() && !gameMap.atStore() && !gameMap.atBoss() )
				{
					mainPlayer.rest( true );
					monster = gameMap.checkRandomEncounter( true );

					while( true )
					{
						mainPlayer.displayHitPoints();
						monster->displayHitPoints();
						cout << endl;

						if( mainPlayer.attack( *monster ) )
						{
							int fleeing = Random( 4, 1 );
							
							if( fleeing == 1 )
								gameMap.forceMovePlayer( 1, 0 );
							else if( fleeing == 2 )
								gameMap.forceMovePlayer( -1, 0 );
							else if( fleeing == 3 )
								gameMap.forceMovePlayer( 0, 1 );
							else if( fleeing == 4 )
								gameMap.forceMovePlayer( 0, -1 );
							break;
						}

						if( monster->isDead() )
						{
							mainPlayer.victory( monster->getXPReward(), monster->getGPReward() );
							mainPlayer.levelUp();
							break;
						}

						monster->attack( mainPlayer );

						if( mainPlayer.isDead() )
						{
							mainPlayer.gameover();
							done = true;
							break;
						}
					}

					delete monster;
					monster = 0;
					break;
				}
				else
				{
					mainPlayer.rest( false );
					break;
				}
			}
			else if( selection == 3 )
			{
				mainPlayer.viewStats();
				break;
			}
			else if( selection == 4 )
			{
				gameMap.checkMap();
				break;
			}
			else if( selection == 5 )
			{
				cout << "Thank you for playing!" << endl;
				done = true;
				break;
			}
		}
	}
}
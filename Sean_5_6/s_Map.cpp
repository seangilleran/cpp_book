// Sean Gilleran
// Chapter 5 Game
// s_Map.cpp

#include <iostream>
#include "s_Map.h"

// Constructor
Map::Map()
{
	// Player starts at origin (0,0)
	mPlayerXPos = 0;
	mPlayerYPos = 0;
}

// Methods
int Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPlayerYPos;
}

bool Map::movePlayer()
{
	int selection = 1;

	while( true )
	{
		std::cout << "Select a Direction:" << std::endl;
		std::cout << " 1)North" << std::endl;
		std::cout << " 2)South" << std::endl;
		std::cout << " 3)East" << std::endl;
		std::cout << " 4)West" << std::endl;
		std::cout << " 5)Cancel" << std::endl;
		std::cout << ">";
		std::cin >> selection;
		std::cout << std::endl;

		if( selection == 1 )
		{
			mPlayerYPos++;
			break;
		}
		else if( selection == 2 )
		{
			mPlayerYPos--;
			break;
		}
		else if( selection == 3 )
		{
			mPlayerXPos++;
			break;
		}
		else if( selection == 4 )
		{
			mPlayerXPos--;
			break;
		}
		else if( selection == 5 )
		{
			return false;
			break;
		}

		std::cout << std::endl;
	}

	return true;
}

Monster* Map::checkRandomEncounter( bool force )
{
	int roll = Random( 20 );
	int forceRoll = Random( 3, 1 );
	Monster *monster = 0;

	if( roll <= 5 && !force )
		// No encounter, return a null pointer
		return 0;
	else if( ( roll >= 6 && roll <= 10 && !force ) || ( forceRoll == 1 && force ) )
	{
		monster = new Monster( "Orc", 10, 8, 200, 50, 1, "Short Sword", 2, 7 );
		std::cout << "You encounter an Orc!" << std::endl;
		std::cout << "Prepare for battle..." << std::endl;
		std::cout << std::endl;
	}
	else if( ( roll >= 11 && roll <= 15 && !force ) || ( forceRoll == 2 && force ) )
	{
		monster = new Monster( "Goblin", 6, 6, 100, 25, 0, "Dagger", 1, 5 );
		std::cout << "You encounter a Goblin!" << std::endl;
		std::cout << "Prepare for battle..." << std::endl;
		std::cout << std::endl;
	}
	else if( ( roll >= 16 && roll <= 19 && !force ) || ( forceRoll == 3 && force ) )
	{
		monster = new Monster( "Ogre", 20, 12, 500, 125, 2, "Club", 2, 8 );
		std::cout << "You encounter an Ogre!" << std::endl;
		std::cout << "Prepare for battle..." << std::endl;
		std::cout << std::endl;
	}
	else if( roll == 20 && !force )
	{
		monster = new Monster( "Orc Lord", 25, 15, 2000, 500, 5, "Claymore", 5, 20 );
		std::cout << "You encounter an Orc Lord!" << std::endl;
		std::cout << "Prepare for battle..." << std::endl;
		std::cout << std::endl;
	}

	return monster;
}

void Map::forceMovePlayer( int x, int y )
{
	mPlayerXPos += x;
	mPlayerYPos += y;
}

void Map::checkMap()
{
	std::cout << "You check your map..." << std::endl;
	std::cout << " Your Position: (" << mPlayerXPos << "," << mPlayerYPos << ")" << std::endl;
	std::cout << " Your Castle:   (0,0)" << std::endl;
	std::cout << " Enemy Castle:  (20,14)" << std::endl;
	std::cout << " Item Shop:     (4,-2)" << std::endl;
	std::cout << std::endl;
}

bool Map::atHome()
{
	return mPlayerXPos == 0 && mPlayerYPos == 0;
}

bool Map::atStore()
{
	return mPlayerXPos == 4 && mPlayerYPos == -2;
}

bool Map::atBoss()
{
	return mPlayerXPos == 20 && mPlayerYPos == 14;
}
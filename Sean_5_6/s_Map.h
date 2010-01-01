// Sean Gilleran
// Chapter 5 Game
// s_Map.h

#ifndef MAP_H
#define MAP_H

#include <string>
#include "s_Weapon.h"
#include "s_Monster.h"

class Map
{
public:
	// Constructor
	Map();

	// Methods
	int getPlayerXPos();
	int getPlayerYPos();
	bool movePlayer();
	void forceMovePlayer( int x, int y );
	Monster* checkRandomEncounter( bool force );
	void checkMap();

	bool atHome();
	bool atBoss();
	bool atStore();

private:
	// Data Members
	int mPlayerXPos;
	int mPlayerYPos;
};

#endif //MAP_H
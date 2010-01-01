// Sean Gilleran
// Chapter 5 Game
// s_Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "s_Weapon.h"
#include "s_Monster.h"
#include "s_Spell.h"

class Player
{
public:
	// Constructor
	Player();

	// Methods
	bool isDead();

	std::string getName();
	int getArmor();

	void takeDamage( int damage );

	void createClass();
	bool attack( Monster &monster );
	void levelUp();
	void rest( bool interrupted );
	void viewStats();
	void victory( int xp, int gp );
	void gameover();
	void displayHitPoints();

private:
	// Data Members
	std::string mName;
	std::string mClassName;
	std::string mRaceName;
	int mAccuracy;
	int mHitPoints;
	int mMaxHitPoints;
	int mMagicPoints;
	int mMaxMagicPoints;
	int mExpPoints;
	int mNextLevelExp;
	int mGold;
	int mLevel;
	int mArmor;
	Weapon mWeapon;
};

#endif //PLAYER_H
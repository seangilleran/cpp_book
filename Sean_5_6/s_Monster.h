// Sean Gilleran
// Chapter 5 Game
// s_Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "s_Weapon.h"
#include "s_Random.h"
#include "s_Spell.h"

class Player;

class Monster
{
public:
	// Constructor
	Monster( const std::string &name, int hp, int acc, int xpReward,
			 int gpReward, int armor, const std::string &weaponName,
			 int lowDamage, int highDamage );

	// Methods
	bool isDead();

	void attack( Player &player );
	void takeDamage( int damage );
	Spell* takeSpellDamage( std::string PlayerClass );
	void displayHitPoints();

	int getXPReward();
	int getGPReward();
	std::string getName();
	int getArmor();

private:
	// Data Members
	std::string mName;
	int			mHitPoints;
	int			mAccuracy;
	int			mExpReward;
	int			mGPReward;
	int			mArmor;
	Weapon		mWeapon;
};

#endif //MONSTER_H
// Sean Gilleran
// Chapter 5 Game
// s_Monster.cpp

#include <iostream>
#include "s_Monster.h"
#include "s_Player.h"

// Constructor
Monster::Monster( const std::string &name, int hp, int acc,
				  int xpReward, int gpReward, int armor,
				  const std::string &weaponName, int lowDamage,
				  int highDamage )
{
	mName = name;
	mHitPoints = hp;
	mAccuracy = acc;
	mExpReward = xpReward;
	mGPReward = gpReward;
	mArmor = armor;
	mWeapon.mName = weaponName;
	mWeapon.mDamageRange.mHigh = highDamage;
	mWeapon.mDamageRange.mLow = lowDamage;
}

// Methods
bool Monster::isDead()
{
	return mHitPoints <= 0;
}

void Monster::attack( Player &player )
{
	std::cout << "The " << mName << " attacks you with a "
		<< mWeapon.mName << std::endl;

	if( Random( 20 ) < mAccuracy )
	{
		int damage = Random( mWeapon.mDamageRange );
		int totalDamage = damage - player.getArmor();

		if( totalDamage <= 0 )
			std::cout << "Blocked!" << std::endl;
		else
		{
			std::cout << mName << " hits you for " << totalDamage
				<< " damage!" << std::endl;

			player.takeDamage( totalDamage );
		}
	}
	else
		std::cout << "Miss!" << std::endl;
	std::cout << std::endl;
}

Spell* takeSpellDamage( std::string PlayerClass )
{
	int selection = 1;

	if( PlayerClass == "Wizard" )
	{
		while( true )
		{
			std::cout << "Select a Spell:" << std::endl;
			std::cout << " 1)Fireball" << std::endl;
			std::cout << " 2)Ice Blast" << std::endl;
			std::cout << " 3)Shield" << std::endl;
			std::cout << " 4)Drain" << std::endl;
			std::cout << " 5)Cancel" << std::endl;
			std::cout << ">";
			std::cin >> selection;

			if( selection == 1 )
			{
				Spell *retSpell = new Spell;

				retSpell.mName = "Fireball";
				retSpell.mDamage.mHigh = 


void Monster::takeDamage( int damage )
{
	mHitPoints -= damage;
}

void Monster::displayHitPoints()
{
	std::cout << mName << "'s HP: " << mHitPoints << std::endl;
}

int Monster::getXPReward()
{
	return mExpReward;
}

int Monster::getGPReward()
{
	return mGPReward;
}

std::string Monster::getName()
{
	return mName;
}

int Monster::getArmor()
{
	return mArmor;
}
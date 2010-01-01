// Sean Gilleran
// Chapter 5 Game
// s_Player.cpp

#include <iostream>
#include "s_Player.h"
#include "s_Monster.h"

// Constructor
Player::Player()
{
	mName		  = "Default";
	mClassName	  = "Default";
	mRaceName	  = "Default";
	mAccuracy	  = 0;
	mHitPoints	  = 0;
	mMaxHitPoints = 0;
	mMagicPoints  = 0;
	mMaxMagicPoints = 0;
	mExpPoints	  = 0;
	mNextLevelExp = 1000;
	mGold		  = 0;
	mLevel		  = 1;
	mArmor		  = 0;
	mWeapon.mName = "Default";
	mWeapon.mDamageRange.mHigh = 0;
	mWeapon.mDamageRange.mLow = 0;
}

// Methods
bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

void Player::takeDamage( int damage )
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	// Input Name
	std::cout << "Enter your name: ";
	std::getline( std::cin, mName );
	std::cout << std::endl;

	// Race Selection
	int raceNum = 1;

	while( true )
	{
		std::cout << "Select your race:" << std::endl;
		std::cout << " 1)Human" << std::endl;
		std::cout << " 2)Elf" << std::endl;
		std::cout << " 3)Dwarf" << std::endl;
		std::cout << ">";
		std::cin >> raceNum;
		std::cout << std::endl;

		if( raceNum == 1 )
		{
			mRaceName = "Human";
			break;
		}
		else if( raceNum == 2 )
		{
			mRaceName = "Elf";
			mAccuracy += 2;
			mMaxHitPoints -= 4;
			break;
		}
		else if( raceNum == 3 )
		{
			mRaceName = "Dwarf";
			mAccuracy -= 1;
			mMaxHitPoints += 8;
			break;
		}
	}

	// Class Selection
	int characterNum = 1;

	while( true )
	{
		std::cout << "Select your class:" << std::endl;
		std::cout << " 1)Fighter" << std::endl;
		std::cout << " 2)Wizard" << std::endl;
		std::cout << " 3)Cleric" << std::endl;
		std::cout << " 4)Thief" << std::endl;
		std::cout << ">";
		std::cin >> characterNum;
		std::cout << std::endl;

		if( characterNum == 1 )
		{
			mClassName	  = "Fighter";
			mAccuracy	  += 10;
			mMaxHitPoints += 20;
			mHitPoints	  = mMaxHitPoints;
			mArmor		  = 4;
			mWeapon.mName = "Long Sword";
			mWeapon.mDamageRange.mHigh = 8;
			mWeapon.mDamageRange.mLow  = 1;
			break;
		}
		else if( characterNum == 2 )
		{
			mClassName	  = "Wizard";
			mAccuracy	  += 5;
			mMaxHitPoints += 10;
			mHitPoints	  = mMaxHitPoints;
			mMaxMagicPoints  = 20;
			mMagicPoints  = mMaxMagicPoints;
			mArmor		  = 1;
			mWeapon.mName = "Staff";
			mWeapon.mDamageRange.mHigh = 4;
			mWeapon.mDamageRange.mLow  = 1;
			break;
		}
		else if( characterNum == 3 )
		{
			mClassName	  = "Cleric";
			mAccuracy	  += 8;
			mMaxHitPoints += 15;
			mHitPoints	  = mMaxHitPoints;
			mMaxMagicPoints  = 10;
			mMagicPoints  = mMaxMagicPoints;
			mArmor		  = 3;
			mWeapon.mName = "Flail";
			mWeapon.mDamageRange.mHigh = 6;
			mWeapon.mDamageRange.mLow  = 1;
			break;
		}
		else if( characterNum == 4 )
		{
			mClassName	  = "Thief";
			mAccuracy	  += 12;
			mMaxHitPoints += 12;
			mHitPoints	  = mMaxHitPoints;
			mMaxMagicPoints += 5;
			mMagicPoints  = mMaxMagicPoints;
			mArmor		  = 2;
			mWeapon.mName = "Short Sword";
			mWeapon.mDamageRange.mHigh = 6;
			mWeapon.mDamageRange.mLow  = 1;
			break;
		}
	}
}

bool Player::attack( Monster &monster )
{
	int selection = 1;

	while( true )
	{
		std::cout << "Select an Action:" << std::endl;
		std::cout << " 1)Attack" << std::endl;
		std::cout << " 2)Magic" << std::endl;
		std::cout << " 3)Run" << std::endl;
		std::cout << ">";
		std::cin >> selection;
		std::cout << std::endl;

		if( selection == 1 )
		{
			std::cout << "You attack the " << monster.getName()
				<< " with your " << mWeapon.mName << std::endl;

			if( Random( 20 ) < mAccuracy )
			{
				int damage = Random( mWeapon.mDamageRange );
				int totalDamage = damage - monster.getArmor();

				if( totalDamage <= 0 )
					std::cout << "Blocked!" << std::endl;
				else
				{
					std::cout << "You hit the " << monster.getName()
						<< " for " << totalDamage << " damage!" << std:: endl;

					monster.takeDamage( totalDamage );
				}
			}
			else
				std::cout << "Miss!" << std::endl;

			std::cout << std::endl;
			break;
		}
		else if( selection == 2 )
		{
			int spellSelect = 1;
			while( true )
			{
				
		else if( selection == 3 )
		{
			if( Random( 4, 1 ) == 1 )
			{
				std::cout << "You flee into the woods!" << std::endl;
				std::cout << std::endl;
				return true;
			}
			else
				std::cout << "You could not escape!" << std::endl;
				std::cout << std::endl;

			break;
		}
	}

	return false;
}

void Player::levelUp()
{
	if( mExpPoints >= mNextLevelExp )
	{
		std::cout << "You gained a level!" << std::endl;

		// Increment Level
		mLevel++;

		// Set experience points required for next level
		mNextLevelExp = mLevel * mLevel * 1000;

		// Increase Stats based on Class
		int plus_Acc = 0;
		int plus_HP = 0;
		int plus_MP = 0;
		int plus_Arm = 0;
		
		if( mClassName == "Fighter" )
		{
			plus_Acc = Random( 3, 1 );
			plus_HP = Random( 8, 4 );
			plus_Arm = Random( 2, 1 );

		}
		else if( mClassName == "Wizard" )
		{
			plus_Acc = Random( 2, 1 );
			plus_HP = Random( 4, 1 );
			plus_MP = Random( 8, 4 );
			plus_Arm = 1;
		}
		else if( mClassName == "Cleric" )
		{
			plus_Acc = Random( 3, 1 );
			plus_HP = Random( 6, 2 );
			plus_MP = Random( 4, 1 );
			plus_Arm = Random( 2, 1 );
		}
		else if( mClassName == "Thief" )
		{
			plus_Acc = Random( 4, 1 );
			plus_HP = Random( 5, 1 );
			plus_MP = Random( 3, 1 );
			plus_Arm = 1;
		}

		// Take race into effect
		if( mRaceName == "Elf" )
		{
			plus_Acc++;
			plus_HP--;
		}
		else if( mRaceName == "Dwarf" )
		{
			plus_HP += 2;
			plus_Acc--;
		}

		// Display the results
		if( plus_HP > 0 )
		{
			std::cout << " HP +" << plus_HP << std::endl;
			mMaxHitPoints += plus_HP;
		}
		if( plus_MP > 0 )
		{
			std::cout << " MP +" << plus_MP << std::endl;
			mMaxMagicPoints += plus_MP;
		}
		if( plus_Acc > 0 )
		{
			std::cout << " Accuracy +" << plus_Acc << std::endl;
			mAccuracy += plus_Acc;
		}
		if( plus_Arm > 0 )
		{
			std::cout << " Armor +" << plus_Arm << std::endl;
			mArmor += plus_Arm;
		}

		// Refresh HP
		mHitPoints = mMaxHitPoints;
		mMagicPoints = mMaxMagicPoints;

		std::cout << std::endl;
	}
}

void Player::rest( bool interrupted )
{
	std::cout << "Resting..." << std::endl;

	if( interrupted )
		std::cout << "Interrupted!" << std::endl;
	else
	{
		mHitPoints = mMaxHitPoints;
		mMagicPoints = mMaxMagicPoints;
	}

	std::cout << std::endl;
}

void Player::viewStats()
{
	std::cout << "Your Stats:" << std::endl;
	std::cout << " " << mName << std::endl;
	std::cout << " Level " << mLevel << " " << mRaceName << " " << mClassName << std::endl;
	std::cout << " HP: " << mHitPoints << "/" << mMaxHitPoints << std::endl;
	if( mMaxMagicPoints > 0 )
		std::cout << " MP: " << mMagicPoints << "/" << mMaxMagicPoints << std::endl;
	std::cout << " XP: " << mExpPoints << "/" << mNextLevelExp << std::endl;
	std::cout << " GP: " << mGold << std::endl;
	std::cout << " " << mArmor << " Armor" << std::endl;
	std::cout << " Using " << mWeapon.mName << std::endl;
	std::cout << " " << mWeapon.mDamageRange.mLow << " to " << mWeapon.mDamageRange.mHigh << " Damage" << std::endl;
	std::cout << " " << mAccuracy << " Accuracy" << std::endl;
	std::cout << std::endl;
}

void Player::victory( int xp, int gp )
{
	std::cout << "You won the battle!" << std::endl;
	std::cout << "You gain " << xp << " xp and " << gp << " gp." << std::endl;
	std::cout << std::endl;

	mExpPoints += xp;
	mGold += gp;
}

void Player::gameover()
{
	std::cout << "You died in battle!" << std::endl;
	std::cout << "GAME OVER" << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to quit...";
	std::cin.get();
}

void Player::displayHitPoints()
{
	std::cout << "Your HP: " << mHitPoints << "/" << mMaxHitPoints << std::endl;
	std::cout << "Your MP: " << mMagicPoints << "/" << mMaxMagicPoints << std::endl;
}
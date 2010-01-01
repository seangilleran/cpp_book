// Sean Gilleran
// Chapter 5 Game
// s_Spell.h

#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "s_Range.h"

struct Spell
{
	std::string mName;
	Range mDamage;
	Range mHealing;
	int	mShield;
	int	mDrain;
	int	mpCost;
};

#endif //SPELL_H
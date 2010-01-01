// Sean Gilleran
// Chapter 5 Game
// s_Weapon.h

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "s_Range.h"

struct Weapon
{
	std::string mName;
	Range mDamageRange;
};

#endif //WEAPON_H
// Sean Gilleran
// Chapter 5 Game
// s_Random.cpp

#include <cstdlib>
#include "s_Random.h"

// Return random # in range R
int Random( Range r )
{
	return r.mLow + rand() % ( ( r.mHigh + 1 ) - r.mLow );
}

// Return random # in range [low, high]
int Random( int high, int low )
{
	return low + rand() % ( ( high + 1 ) - low );
}
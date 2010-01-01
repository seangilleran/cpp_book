// Sean Gilleran
// Vector Class
// s_String.cpp

#include "s_String.h"

String::String( const char *rhs )
{
	// Get the length of the rhs c-string
	int len = strlen( rhs );

	// Allocate enough memory to store a copy of the
	// c-string plus one more for null-character
	mData = new char[len + 1];

	// Copy characters over to our own data
	for( int = i = 0; i < len ++
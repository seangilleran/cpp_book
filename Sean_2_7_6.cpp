// Assignment 2.7.6
// Sean Gilleran

#include <iostream>
using namespace std;

int main()
{
	// Run through all the ASCII #s, as specificied in the assignment
	for( int index = 33; index <= 255; ++index )
	{
		// Align them by putting a space before two digit #s
		if( index < 100 )
			cout << " ";

		// Print the ASCII value as a char
		cout << index << ": " << static_cast <char> ( index ) << endl;
	}

	return 0;
}
// Sean Gilleran
// Assignment 3.7.1

#include <iostream>
using namespace std;

int Factorial( int n )
{
	for( int index = ( n - 1 ); index > 0; index-- )
		n *= index;

	return n;
}

int main()
{
	int input;
	char again;

	while( true )
	{
		cout << "Enter an integer to Factorialize: ";
		cin >> input;

		cout << input << "! = " << Factorial( input ) << endl;
		cout << "Again? ";
		cin >> again;

		if( again != 'Y' && again != 'y' )
			break;
	}

	return 0;
}


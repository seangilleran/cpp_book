// Sean Gilleran
// 12.8.5 Binary to Decimal
// Sean_12_8_5.cpp

#include <iostream>
#include <string>
using namespace std;

unsigned BinToDec( const string &binary )
{
	// Error Messages
	const string BAD_INPUT = "ERR: Not an unsigned binary number!";
	const string MEM_OVER = "ERR: Input too big! Out of memory.";

	// First make sure the input isn't too big; an unsigned
	//  variable can only handle 32 binary digits
	if( binary.length() > 32 )
		throw MEM_OVER;

	unsigned decimal = 0;	// Number to store a running tally
							//  This is what we'll return.
	unsigned factor = 1;	// Number to store the decimal value
							//  of the currently examined place.

	// Take the string, and look at each digit. Start the
	// decimal tally at zero. First, look at the ones place.
	// If there's a 1, add 1 to your tally. Then look at
	// the twos place. if there's a 1, add 2 to your tally.
	// Then, look at the fours place. If there's a 4, add
	// 4 to your tally, and so on. Return the final result.

	// Start at the end of the string and count down
	for( int index = binary.length() - 1; index >= 0; index-- )
	{
		if( binary[index] == '1' )	// Is it a 1?
			decimal += factor;		// Add the current decimal value
		else if( binary[index] != '0' )
			throw BAD_INPUT;	// We've been had! This isn't binary.

		factor *= 2;			// Update the current decimal value
	}

	// This works on the principle of
	//  10101 = 10000 + 00100 + 00001 = 16 + 4 + 1 = 21
	// Admittedly it's pretty inelegant, but it works!
	return decimal;
}

int main()
{
	string input = " ";

	cout << "Enter an unsigned binary number: ";
	getline( cin, input );

	try {
		cout << input << " = " << BinToDec( input ) << endl;
	}
	catch( string err ) {
		cout << err << endl;
	}

	return 0;
}
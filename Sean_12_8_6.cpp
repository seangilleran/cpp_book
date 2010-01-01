// Sean Gilleran
// 12.8.6 Decimal to Binary
// Sean_12_8_6.cpp

#include <iostream>
#include <string>
using namespace std;

string DecToBin( unsigned decimal )
{
	// Explanation:
	//  http://www.trunix.org/programlama/cpp/fred/notes/cpp/misc/decimal2binary.html

	string binary = "";

	while( decimal > 0 )
	{
		// Insert the current decimal # at the beginning of the string
		binary.insert( binary.begin(), static_cast <char> ( ( decimal % 2 ) + '0' ) );
		decimal /= 2;
	}

	if( binary == "" ) binary = "0";
	return binary;
}

int main()
{
	unsigned input = 0;

	cout << "Enter an unsigned integer: ";
	cin >> input;
	cout << input << " = " << DecToBin( input ) << endl;

	return 0;
}
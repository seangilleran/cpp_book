// Sean Gilleran
// 3.7.2

#include <iostream>
using namespace std;

char ToUpperCase( char c )
{
	if( c >= 97 && c <= 122 )
		c -= 32;
	else if( c < 65 && c > 90 )
		c = NULL;

	return c;
}

char ToLowerCase( char c )
{
	if( c >= 65 && c <= 90 )
		c += 32;
	else if( c < 97 && c > 122 )
		c = NULL;

	return c;
}

int main()
{
	char input;

	cout << "Input char: ";
	cin >> input;

	cout << ToLowerCase( input ) << " " << ToUpperCase( input ) << endl;

	return 0;
}
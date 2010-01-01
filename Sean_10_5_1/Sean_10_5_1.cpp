// Sean Gilleran
// 10.5.1 Array Class
// Sean_10_5_1.cpp

#include <iostream>
#include <string>
#include "s_Array.h"
using namespace std;

int main()
{
	Array<int> a1( 3 );

	for( int index = 0; index < a1.size(); index++ )
		a1[index] = index;

	for( int index = 0; index < a1.size(); index++ )
		cout << a1[index] << " ";
	cout << endl;

	a1.pop();

	for( int index = 0; index < a1.size(); index++ )
		cout << a1[index] << " ";
	cout << endl;

	a1.push( -5 );

	for( int index = 0; index < a1.size(); index++ )
		cout << a1[index] << " ";
	cout << endl;

	Array<string> a2( 1 );

	a2[0] = "Hello";

	cout << a2[0] << endl;

	a2.resize( 2 );

	a2[1] = " World";

	cout << a2[0] << a2[1];

	a2.push( "!" );

	cout << a2[2] << endl;

	return 0;
}
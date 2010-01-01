// Sean Gilleran
// 10.5.3 Table Driver
// Sean_10_5_3.cpp

#include <iostream>
#include "s_Table.h"
using namespace std;

int main()
{
	Table<int> A( 2, 3 );
		A( 0, 0 ) = -5;
		A( 0, 1 ) = 2;
		A( 0, 2 ) = 8;
		A( 1, 0 ) = 1;
		A( 1, 1 ) = 0;
		A( 1, 2 ) = 0;
	Table<int> B( 2, 3 );
		B( 0, 0 ) = 1;
		B( 0, 1 ) = 0;
		B( 0, 2 ) = 2;
		B( 1, 0 ) = 0;
		B( 1, 1 ) = 3;
		B( 1, 2 ) = -6;

	cout << "A = " << endl;
	for( int i = 0; i < A.nRows(); ++i )
	{
		for( int j = 0; j < A.nCols(); ++ j )
			cout << A( i, j ) << " ";
		cout << endl;
	}
	cout << endl;

	cout << "B = " << endl;
	for( int i = 0; i < B.nRows(); ++i )
	{
		for( int j = 0; j < B.nCols(); ++ j )
			cout << B( i, j ) << " ";
		cout << endl;
	}
	cout << endl;

	cout << "A + B = " << endl;
	for( int i = 0; i < A.nRows(); ++i )
	{
		for( int j = 0; j < A.nCols(); ++ j )
			cout << A( i, j ) + B( i, j ) << " ";
		cout << endl;
	}
	cout << endl;
	
	return 0;
}
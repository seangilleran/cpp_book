// Sean Gilleran
// 10.5.2 Bubble Sort Function
// Sean_10_5_2.cpp

#include <iostream>
using namespace std;

template <typename T>
void BubbleSort( T data[], int size )
{
	T array_Swap = 0;

	// This is necessary to prevent the program from accessing
	// memory beyond the scope of the array

	int n = ( size - 1 );

	// Run through the whole array and sort it piece by piece,
	// then, now that the largest number must necessarily be
	// at the end of the array, run through the array except
	// for the last element, then the second to last, etc.,
	// until the whole thing is sorted.

	for( int start_I = 0; start_I < n; start_I++ )
		for( int cur_I = 0; cur_I < ( n - start_I ); cur_I++ )
			if( data[cur_I] > data[( cur_I + 1 )] )
			{
				array_Swap = data[cur_I];
				data[cur_I] = data[( cur_I + 1 )];
				data[( cur_I + 1 )] = array_Swap;
			}
}

int main()
{
	int test[5];

	test[0] = 11;
	test[1] = -2;
	test[2] = 20;
	test[3] = 7;
	test[4] = -1;

	for( int index = 0; index < 5; index++ )
		cout << "test[" << index << "] = " << test[index] << endl;
	cout << endl;

	BubbleSort( test, 5 );
	cout << "BubbleSort( test, 5 );" << endl;
	cout << endl;

	for( int index = 0; index < 5; index++ )
		cout << "test[" << index << "] = " << test[index] << endl;
	cout << endl;

	return 0;
}
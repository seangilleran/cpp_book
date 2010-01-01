// Sean Gilleran
// 3.7.8

#include <iostream>
using namespace std;

void BubbleSort( int data[], int n )
{
	int array_Swap;

	// This is necessary to prevent the program from accessing
	// memory beyond the scope of the array

	n -= 1;

	// Run through the whole array and sort it piece by piece,
	// then, now that the largest number must necessarily be
	// at the end of the array, run through the array except
	// for the last element, then the second to last, etc.,
	// until the whole thing is sorted.

	for( int start_I = 0; start_I < n; start_I++ )
	{
		for( int cur_I = 0; cur_I < ( n - start_I ); cur_I++ )
		{
			if( data[cur_I] > data[( cur_I + 1 )] )
			{
				array_Swap = data[cur_I];
				data[cur_I] = data[( cur_I + 1 )];
				data[( cur_I + 1 )] = array_Swap;
			}
		}
	}
}

int BinSearch( int data[], int n, int search_Key )
{
	int return_Key = -1;

	if( search_Key > data[( n / 2 )] )
	{
		for( int i = ( n / 2 ); i < n; i++ )
			if( data[i] == search_Key )
				return_Key = search_Key;
	}
	else if( search_Key < data[( n / 2 )] )
	{
		for( int i = ( n / 2 ); i >= 0; i-- )
			if( data[i] == search_Key )
				return_Key = search_Key;
	}
	else if( search_Key == data[( n / 2 )] )
		return_Key = search_Key;

	return return_Key;
}

int main()
{
	// Here are the variable declarations; changing NUM_ELEMENTS
	// will adjust the entire program to accept a different
	// quantity of integers

	const int NUM_ELEMENTS = 5;
	int x_Array[NUM_ELEMENTS], search_Key, found_Key;
	char cont;

	while( true )
	{
		// Input the integers into the array using a for loop

		cout << "Enter " << NUM_ELEMENTS << " integers into an array:" << endl;
		for( int i = 0; i < NUM_ELEMENTS; i++ )
		{
			cout << "x_Array[" << i << "] = ";
			cin >> x_Array[i];
		}

		// Print the unsorted array

		cout << "Unsorted Array: { ";
		for( int i = 0; i < NUM_ELEMENTS; i++ )
			cout << x_Array[i] << " ";
		cout << "}" << endl;

		// Sort the array using BubbleSort()

		cout << "Sorting..." << endl;
		BubbleSort( x_Array, NUM_ELEMENTS );

		// Now print the sorted array

		cout << "Sorted Array: { ";
		for( int i = 0; i < NUM_ELEMENTS; i++ )
			cout << x_Array[i] << " ";
		cout << "}" << endl;

		while( true )
		{
			cout << "Continue with this array? (Y/N): ";
			cin >> cont;

			if( cont == 'Y' || cont == 'y' )
				break;
			else if( cont == 'N' || cont == 'n' )
				break;
		}

		if( cont == 'Y' || cont == 'y' )
			break;
	}

	while( true )
	{
		cout << "Enter an integer to search the array for: ";
		cin >> search_Key;
		found_Key = BinSearch( x_Array, NUM_ELEMENTS, search_Key );

		if( found_Key != -1 )
			cout << search_Key << " found at element " << found_Key << endl;
		else
			cout << search_Key << " not found in array!" << endl;

		while( true )
		{
			cout << "Search Again? (Y/N): ";
			cin >> cont;

			if( cont == 'Y' || cont == 'y' )
				break;
			else if( cont == 'N' || cont == 'n' )
				break;
		}

		if( cont == 'N' || cont == 'n' )
			break;
	}

	return 0;
}
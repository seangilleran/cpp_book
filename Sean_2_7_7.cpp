// Assignment 2.7.7
// Sean Gilleran

#include <iostream>
using namespace std;

int main()
{
	// Hard-coded array, as specified
	const int LIST_SIZE = 17;
	int list[] = { 7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8 };

	// Print the array, first of all
	cout << "List = ";

	for( int index = 0; index < LIST_SIZE; index++ )
	{
		cout << list[index] << ", ";
	}

	cout << endl;


	// Now for the search bit
	int search = 0;

	cout << "Enter an integer in the list to search for: ";
	cin >> search;

	for( int index = 0; index < LIST_SIZE; index ++ )
	{
		// Found it!
		if( search == list[index] )
		{
			cout << "Item found at index [" << index << "]" << endl;
			break;
		}

		// No dice
		else if( index == ( LIST_SIZE - 1 ) )
			cout << "Item not found!" << endl;
	}

	return 0;
}
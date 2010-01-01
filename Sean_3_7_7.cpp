// Sean Gilleran
// 3.7.7

#include <iostream>
using namespace std;

int BinSearch( int data[], int numElements, int searchKey )
{
	int currentElement = numElements / 2;

	while( true )
	{
		if( currentElement < 0 || currentElement >= numElements )
			currentElement = -1;
		else
		{
			if( data[currentElement] < searchKey )
				currentElement++;
			else if( data[currentElement] > searchKey )
				currentElement--;
			else if( data[currentElement] == searchKey )
				break;
		}
	}

	return currentElement;
}

int main()
{
	int test_Array[] = { 1, 4, 5, 6, 9, 14, 21, 22,
		23, 28, 31, 35, 42, 46, 50, 53, 57, 62, 63,
		65, 74, 79, 89, 95 }, search;
	char selection;

	while( true )
	{
		cout << "(S)earch or (Q)uit: ";
		cin >> selection;

		if( selection == 'Q' || selection == 'q' )
			break;
		else if( selection == 'S' || selection == 's' )
		{
			cout << "test_Array[] = { ";
			for( int index = 0; index < 24; index++ )
				cout << test_Array[index] << " ";
			cout << "}" << endl;

			cout << "Enter search key: ";
			cin >> search;
			
			cout << search << " is at position " << BinSearch( test_Array, 24, search ) << endl;
		}
	}

	return 0;
}

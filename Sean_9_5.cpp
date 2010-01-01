#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int input = 0;

	while( true )
	{
		// Output size
		cout << "vec.size() = " << vec.size() << endl;

		// Output vector contents
		cout << "vec = { ";
		for( int index = 0; (unsigned)index < vec.size(); index++ )
			cout << vec[index] << " ";
		cout << "}" << endl;
		cout << endl;

		// Option menu
		while( true )
		{
			cout << "1) Add int, 2) Remove int, 3) Delete last 4) Exit: ";
			cin >> input;

			if( input == 1 || input == 2 || input == 3 || input == 4 )
				break;
		}

		// Do operation based on item chosen
		if( input == 1 )
		{
			// Add an integer into the vector
			cout << "Enter an integer: ";
			cin >> input;
			vec.push_back( input );
		}
		else if( input == 2 )
		{
			// Remove the element at the inputted location
			cout << "Enter the index of an integer to remove: ";
			cin >> input;

			if( input > 0 && (unsigned)input < vec.size() )
				vec.erase( vec.begin() + input );
			else
				cout << "Index not found." << endl;
		}
		else if( input == 3 )
			vec.pop_back();
		else if( input == 4 )
			break;
	}

	return 0;
}

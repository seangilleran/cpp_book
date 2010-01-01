// Sean Gilleran
// 11.5.1 Exception Handling
// Sean_11_5_1.cpp

#include <iostream>
#include <string>
using namespace std;

const string BAD_INPUT_SMALL = "ERR: Bad Input! Number too small.";
const string BAD_INPUT_LARGE = "ERR: Bad Input! Number too big.";

int main()
{
	int test = 0;
	cout << "Enter a number between 1 and 10: ";
	cin >> test;

	try {
		if( test >= 1 && test <= 10 )
			cout << "test = " << test << endl;
		else if( test < 1 )
			throw BAD_INPUT_SMALL;
		else if( test > 10 )
			throw BAD_INPUT_LARGE;
	}
	catch( string err ) {
		cout << err << endl;
	}

	cout << "Running more code..." << endl;

	return 0;
}

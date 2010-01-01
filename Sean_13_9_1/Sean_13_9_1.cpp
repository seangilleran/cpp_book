// Sean Gilleran
// 13.9.1 Linked List Class
// Sean_13_9_1.cpp

#include <iostream>
#include "s_LinkedList.h"
using namespace std;

int main()
{
	LinkedList<int> test;
	
	for( int index = 0; index < 10; index++ )
		test.push_first( index + 1 );

	cout << "test = ";
	for( int index = 0; index < test.size(); index++ )
		cout << test[index]->data << " ";
	cout << endl;

	test.push_after( 100, 4 );

	cout << "test = ";
	for( int index = 0; index < test.size(); index++ )
		cout << test[index]->data << " ";
	cout << endl;

	test.pop_value( 8 );

	cout << "test = ";
	for( int index = 0; index < test.size(); index++ )
		cout << test[index]->data << " ";
	cout << endl;

	test.push_before( 500, 6 );

	cout << "test = ";
	for( int index = 0; index < test.size(); index++ )
		cout << test[index]->data << " ";
	cout << endl;

	cout << test.first()->data << endl;
	test.pop_first();
	cout << test.first()->data << endl;

	cout << test.find( 6 ) << endl;
	cout << test.find( 1000 ) << endl;

/*	cout << test.size() << endl;
	test.erase();
	cout << test.size() << endl;

	test.push_first( 1 );
	cout << test.size() << endl;
*/
	int size = test.size();
	for( int index = 0; index < size; index++ )
	{
		cout << "test = ";
		for( int index = 0; index < test.size(); index++ )
			cout << test[index]->data << " ";
		cout << endl;
		test.pop_last();
	}
	cout << test.size();

	return 0;
}
// Sean Gilleran
// 4.9.3

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void RandomArrayFill( int *x, int size )
{
	srand( time( 0 ) );

	for( int index = 0; index < size; index++ )
		x[index] = rand() % 100;
}

int main()
{
	int n = 0;

	cout << "Enter the size of an array to create: ";
	cin >> n;

	int *dynArray = new int[n];
	RandomArrayFill( dynArray, n );

	cout << " dynArray[" << n << "] = { ";
	for( int index = 0; index < n; index++ )
		cout << dynArray[index] << " ";
	cout << "}" << endl;

	return 0;
}
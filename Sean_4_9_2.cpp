// Sean Gilleran
// 4.9.2

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Dice( int *die1, int *die2 )
{
	*die1 = 1 + ( rand() % 6 );
	*die2 = 1 + ( rand() % 6 );
}

void Dice( int &die1, int &die2 )
{
	die1 = 1 + ( rand() % 6 );
	die2 = 1 + ( rand() % 6 );
}

int main()
{
	srand( time(0) );
	int x = 0, y = 0;
	int pot = 100, bet = 0;

	while( true )
	{
		cout << "$" << pot << endl;

		while( true )
		{
			cout << "> $";
			cin >> bet;

			if( bet <= pot && bet > 0 )
				break;
		}

		Dice( x, y );

		cout << endl;
		cout << "[" << x << "] [" << y << "]" << endl;
		cout << endl;

		if( x + y == 7 )
		{
			cout << "Lucky 7!" << endl;
			pot += ( bet * 2 );
		}
		else
			pot -= bet;

		if( pot <= 0 )
			break;
	}

	cout << "Game Over!" << endl;

	return 0;
}
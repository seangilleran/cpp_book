// Sean Gilleran
// 3.7.6

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random( int high, int low = 0 )
{
	return low + rand() % ( ( high + 1 ) - low );
}

int Spin( int chips )
{
	int bet, w1, w2, w3;

	while( true )
	{
		cout << "Enter your bet: $";
		cin >> bet;

		if( bet <= chips && bet > 0 )
		{
			w1 = Random( 7, 2 );
			cout << w1 << " ";
			w2 = Random( 7, 2 );
			cout << w2 << " ";
			w3 = Random( 7, 2 );
			cout << w3 << endl;

			if( w1 == 7 && w2 == 7 && w3 == 7 )
				chips += bet * 10;
			else if( w1 == w2 && w2 == w3 )
				chips += bet * 5;
			else if( w1 == w2 || w2 == w3 || w1 == w3 )
				chips += bet * 3;
			else
				chips -= bet;

			break;
		}
	}

	return chips;
}

int main()
{
	srand( time( 0 ) );

	int chips = 1000, selection;
	bool again = true;

	do {
		cout << "Player's chips: $" << chips << endl;
		cout << "1) Play Slot" << endl;
		cout << "2) Quit" << endl;
		cout << ">";
		cin >> selection;

		switch( selection )
		{
		case 1:
			chips = Spin( chips );

			if( chips <= 0 )
				again = false;

			break;
		case 2:
			again = false;
			break;
		}
	} while( again );

	return 0;
}
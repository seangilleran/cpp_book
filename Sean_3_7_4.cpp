// Sean Gilleran
// 3.7.4

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x = 0.0f, y = 0.0f, n = 0.0f;
	int input;

	while( true )
	{
		cout << " 1) cos(x)" << endl;
		cout << " 2) sin(x)" << endl;
		cout << " 3) tan(x)" << endl;
		cout << " 4) acos(x)" << endl;
		cout << " 5) asin(x)" << endl;
		cout << " 6) atan(x)" << endl;
		cout << " 7) sqrt(x)" << endl;
		cout << " 8) ln(x)" << endl;
		cout << " 9) e^x" << endl;
		cout << "10) x^y" << endl;
		cout << "11) |x|" << endl;
		cout << "12) floor(x)" << endl;
		cout << "13) ceiling(x)" << endl;
		cout << "14) Quit" << endl;
		cout << ">";
		cin >> input;

		if( input != 14 )
		{
			cout << "x = ";
			cin >> x;
			cout << endl;

			switch( input )
			{
			case 1:
				n = cosf( x );
				cout << "cos(" << x << ") = ";
				break;
			case 2:
				n = sinf( x );
				cout << "sin(" << x << ") = ";
				break;
			case 3:
				n = tanf( x );
				cout << "tan(" << x << ") = ";
				break;
			case 4:
				n = acosf( x );
				cout << "acos(" << x << ") = ";
				break;
			case 5:
				n = asinf( x );
				cout << "asin(" << x << ") = ";
				break;
			case 6:
				n = atanf( x );
				cout << "atan(" << x << ") = ";
				break;
			case 7:
				n = sqrtf( x );
				cout << "sqrt(" << x << ") = ";
				break;
			case 8:
				n = logf( x );
				cout << "ln(" << x << ") = ";
				break;
			case 9:
				n = expf( x );
				cout << "e^" << x << " = ";
				break;
			case 10:
				cout << "y = ";
				cin >> y;
				n = powf( x, y );
				cout << x << "^" << y  << " = ";
				break;
			case 11:
				n = fabsf( x );
				cout << "|" << x << "| = ";
				break;
			case 12:
				n = floorf( x );
				cout << "floor(" << x << ") = ";
				break;
			case 13:
				n = ceilf( x );
				cout << "ceiling(" << x << ") = ";
				break;
			}

			cout << n << endl << endl;
		}
		else
			break;
	}

	return 0;
}
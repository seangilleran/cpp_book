// Sean Gilleran
// 4.9.4

#include <iostream>
#include <cmath>
using namespace std;

bool QuadraticFormula( float a, float b, float c,
					  float &r1, float &i1, float &r2, float &i2 )
{
	float temp = ( b * b ) - ( 4 * a * c );
	bool i = false;
	
	if( temp < 0 )
	{
		i1 = sqrt( -temp ) / ( 2 * a );
		i2 = sqrt( -temp ) / ( 2 * a );

		r1 = -b / ( 2 * a );
		r2 = -b / ( 2 * a );

		i = true;
	}
	else
	{
		i1 = 0;
		i2 = 0;

		r1 = ( -b + sqrt( ( b * b ) - ( 4 * a * c ) ) ) / ( 2 * a );
		r2 = ( -b - sqrt( ( b * b ) - ( 4 * a * c ) ) ) / ( 2 * a );
	}

	return i;
}

int main()
{
	float a = 0.0f, b = 0.0f, c = 0.0f,
		r1 = 0.0f, i1 = 0.0f, r2 = 0.0f, i2 = 0.0f;
	char again = ' ';

	while( true )
	{
		cout << "Enter a quadratic equation:" << endl;
		cout << "ax2 + bx + c" << endl;
		cout << " a = ";
			cin >> a;
		cout << " b = ";
			cin >> b;
		cout << " c = ";
			cin >> c;
		cout << endl;

		QuadraticFormula( a, b, c, r1, i1, r2, i2 );

		cout << "Intercepts:" << endl;
		if( i1 != 0 )
			cout << " x1 = " << r1 << " + " << i1 << "i" << endl;
		else
			cout << " x1 = " << r1 << endl;

		if( i2 != 0 )
			cout << " x2 = " << r2 << " - " << i2 << "i" << endl;
		else
			cout << " x2 = " << r2 << endl;
		cout << endl;

		cout << "Again? (Y/N): ";
			cin >> again;
		cout << endl;

		if( again == 'N' || again == 'n' )
			break;
	}

	return 0;
}
// Sean
// 3.7.3

#include <iostream>
#include <cmath>
using namespace std;

float dist3( float ux, float uy, float uz,
			 float vx, float vy, float vz );

int main()
{
	cout << dist3( 1, 2, 3, 0, 0, 0 ) << endl;
	cout << dist3( 1, 2, 3, 1, 2, 3 ) << endl;
	cout << dist3( 1, 2, 3, 7, -4, 5 ) << endl;

	return 0;
}

float dist3( float ux, float uy, float uz,
			 float vx, float vy, float vz )
{
	return sqrtf( ((vx-ux) * (vx-ux)) +
				  ((vy-uy) * (vy-uy)) +
				  ((vz-uz) * (vz-uz)) );
}
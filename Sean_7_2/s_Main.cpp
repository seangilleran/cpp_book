// Sean Gilleran
// Vector Class
// s_Main.cpp

#include <iostream>
#include "s_Vector3.h"
using namespace std;

int main()
{
	// Part 1: Construct three vectors
	Vector3 u;
	float coords[3] = { 1.0f, 2.0f, 3.0f };
	Vector3 v( coords );
	Vector3 w( -5.0f, 2.0f, 0.0f );

	// Part 2: Print the vectors
	cout << "u = " << u << endl;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
	cout << endl;

	// Part 3: u = v + w
	u = v + w;
	cout << "v + w = u = " << u << endl;
	cout << endl;

	// Part 4: v = v / ||v||
	v.normalize();
	cout << "v.normalize() = " << v << endl;
	cout << "v.length() = " << v.length() << endl;
	cout << endl;

	// Part 5: dotP = u * w
	float dotP = u * w;
	cout << "u.dot( w ) = " << dotP << endl;
	cout << endl;

	// Part 6: Convert to array representation
	float *vArray = (float*)v;
	cout << "vArray[] = { " << vArray[0] << ", " << vArray[1] << ", " << vArray[2] << " }" << endl;
	cout << endl;

	// Part 7: Create a new vector and have the user input it
	cout << "Input vector..." << endl;
	Vector3 m;
	cin >> m;
	cout << "m = " << m << endl;
	
	return 0;
}
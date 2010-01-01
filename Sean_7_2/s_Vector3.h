// Sean Gilleran
// Vector Class
// s_Vector3.h

#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

class Vector3
{
public:
	// Constructors
	Vector3();
	Vector3( float coords[3] );
	Vector3( float x, float y, float z );

	// Methods
	bool operator == ( const Vector3 &rhs );
	bool operator != ( const Vector3 &rhs );
	Vector3 operator + ( const Vector3 &rhs );
	Vector3 operator - ( const Vector3 &rhs );
	Vector3 operator * ( float scalar );
	float operator * ( const Vector3 &rhs );

	float length();
	void normalize();

	operator float*();

	void print();
	void input();

	// Data Members
	float mX, mY, mZ;
};

// Overloaded cout / cin
std::ostream& operator << ( std::ostream &os, const Vector3 &v );
std::istream& operator >> ( std::istream &is, Vector3 &v );

#endif //VECTOR3_H
// Sean Gilleran
// Vector Class
// s_Vector3.cpp

#include <cmath>
#include "s_Vector3.h"

// ***
// Constructors
// ***

// Create a default Vector3
Vector3::Vector3()
{
	mX = 0.0f;
	mY = 0.0f;
	mZ = 0.0f;
}

// Create a Vector3 from an array
Vector3::Vector3( float coords[3] )
{
	mX = coords[0];
	mY = coords[1];
	mZ = coords[2];
}

// Create a Vector3 from 3 floats
Vector3::Vector3( float x, float y, float z )
{
	mX = x;
	mY = y;
	mZ = z;
}

// ***
// Methods
// ***

bool Vector3::operator == ( const Vector3 &rhs )
{
	return
		mX == rhs.mX &&
		mY == rhs.mY &&
		mZ == rhs.mZ;
}

bool Vector3::operator != ( const Vector3 &rhs )
{
	return
		mX != rhs.mX ||
		mY != rhs.mY ||
		mZ != rhs.mZ;
}

Vector3 Vector3::operator + ( const Vector3 &rhs )
{
	Vector3 sum;
	sum.mX = mX + rhs.mX;
	sum.mY = mY + rhs.mY;
	sum.mZ = mZ + rhs.mZ;
	return sum;
}

Vector3 Vector3::operator - ( const Vector3 &rhs )
{
	Vector3 dif;
	dif.mX = mX - rhs.mX;
	dif.mY = mY - rhs.mY;
	dif.mZ = mZ - rhs.mZ;
	return dif;
}

// Scalar Product
Vector3 Vector3::operator * ( float scalar )
{
	Vector3 p;
	p.mX = mX * scalar;
	p.mY = mY * scalar;
	p.mZ = mZ * scalar;
	return p;
}

// Dot Product
float Vector3::operator * ( const Vector3 &rhs )
{
	float dotP = ( mX * rhs.mX ) + ( mY * rhs.mY ) + ( mZ * rhs.mZ );
	return dotP;
}

float Vector3::length()
{
	return sqrtf( ( mX * mX ) + ( mY * mY ) + ( mZ * mZ ) );
}

// Set length to 1.0 but retain all other properties
void Vector3::normalize()
{
	float len = length();
	mX /= len;
	mY /= len;
	mZ /= len;
}

Vector3::operator float*()
{
	return &mX;
}

void Vector3::print()
{
	std::cout << "<" << mX << "," << mY << "," << mZ << ">" << std::endl;
}

void Vector3::input()
{
	std::cout << "Enter x: ";
	std::cin >> mX;
	std::cout << "Enter y: ";
	std::cin >> mY;
	std::cout << "Enter z: ";
	std::cin >> mZ;
}

std::ostream& operator << ( std::ostream &os, const Vector3 &v )
{
	std::cout << "<" << v.mX << "," << v.mY << "," << v.mZ << ">";
	return os;
}

std::istream& operator >> ( std::istream &is, Vector3 &v )
{
	std::cout << "Enter X: ";
	std::cin >> v.mX;
	std::cout << "Enter Y: ";
	std::cin >> v.mY;
	std::cout << "Enter Z: ";
	std::cin >> v.mZ;
	return is;
}
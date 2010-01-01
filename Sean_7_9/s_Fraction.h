// Sean Gilleran
// Vector Class
// s_Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
public:
	// Constructors
	Fraction();
	Fraction( const float num, const float den );

	// Methods
	Fraction operator + ( const Fraction &rhs );
	Fraction operator - ( const Fraction &rhs );
	Fraction operator * ( const Fraction &rhs );
	Fraction operator / ( const Fraction &rhs );

	bool operator == ( const Fraction &rhs );
	bool operator != ( const Fraction &rhs );
	bool operator < ( const Fraction &rhs );
	bool operator > ( const Fraction &rhs );
	bool operator <= ( const Fraction &rhs );
	bool operator >= ( const Fraction &rhs );

	operator float();

	// Data Members
	float mNum;
	float mDen;
};

// Stream Operators
std::istream& operator >> ( std::istream &is, Fraction &f );
std::ostream& operator << ( std::ostream &os, const Fraction &f );

#endif //FRACTION_H
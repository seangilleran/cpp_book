// Sean Gilleran
// Vector Class
// s_Fraction.cpp

#include "s_Fraction.h"

// Constructors
//************************

Fraction::Fraction()
{
	mNum = 0;
	mDen = 1;
}

Fraction::Fraction( const float num, const float den )
{
	mNum = num;
	mDen = den;
}


// Methods
//************************

Fraction Fraction::operator + ( const Fraction &rhs )
{
	Fraction temp;
	temp.mNum = ( mNum * rhs.mDen ) + ( rhs.mNum * mDen );
	temp.mDen = mDen * rhs.mDen;
	return temp;
}

Fraction Fraction::operator - ( const Fraction &rhs )
{
	Fraction temp;
	temp.mNum = ( mNum * rhs.mDen ) - ( rhs.mNum * mDen );
	temp.mDen = mDen * rhs.mDen;
	return temp;
}

Fraction Fraction::operator * ( const Fraction &rhs )
{
	Fraction temp;
	temp.mNum = mNum * rhs.mNum;
	temp.mDen = mDen * rhs.mDen;
	return temp;
}

Fraction Fraction::operator / ( const Fraction &rhs )
{
	Fraction temp;
	temp.mNum = mNum * rhs.mDen;
	temp.mDen = mDen * rhs.mNum;
	return temp;
}

bool Fraction::operator == ( const Fraction &rhs )
{
	return
		( mNum / mDen ) ==
		( rhs.mNum / rhs.mDen );
}

bool Fraction::operator != ( const Fraction &rhs )
{
	return
		( mNum / mDen ) !=
		( rhs.mNum / rhs.mDen );
}

bool Fraction::operator < ( const Fraction &rhs )
{
	return
		( mNum / mDen ) <
		( rhs.mNum / rhs.mDen );
}

bool Fraction::operator > ( const Fraction &rhs )
{
	return
		( mNum / mDen ) >
		( rhs.mNum / rhs.mDen );
}

bool Fraction::operator <= ( const Fraction &rhs )
{
	return
		( mNum / mDen ) <=
		( rhs.mNum / rhs.mDen );
}

bool Fraction::operator >= ( const Fraction &rhs )
{
	return
		( mNum / mDen ) >=
		( rhs.mNum / rhs.mDen );
}

Fraction::operator float()
{
	return mNum / mDen;
}

std::istream& operator >> ( std::istream &is, Fraction &f )
{
	std::cout << "Enter Numerator: ";
	std::cin >> f.mNum;

	while( true )
	{
		std::cout << "Enter Denominator: ";
		std::cin >> f.mDen;
		
		if( f.mDen != 0 )
			break;
		else
			std::cout << "ERROR!!" << std::endl;
	}

	return is;
}

std::ostream& operator << ( std::ostream &os, const Fraction &f )
{
	if( f.mDen != 1 )
		std::cout << f.mNum << "/" << f.mDen;
	else
		std::cout << f.mNum;

	return os;
}
// Sean Gilleran
// Vector Class
// s_Main_7_9.cpp

#include <iostream>
#include "s_Fraction.h"
using namespace std;

int main()
{
	Fraction frac1, frac2;

	cin >> frac1;
	cin >> frac2;

	Fraction frac_a1 = frac1 + frac2;
	Fraction frac_a2 = frac1 - frac2;
	Fraction frac_a3 = frac1 * frac2;
	Fraction frac_a4 = frac1 / frac2;

	cout << frac_a1 << " = " << (float)frac_a1 << endl;
	cout << frac_a2 << " = " << (float)frac_a2 << endl;
	cout << frac_a3 << " = " << (float)frac_a3 << endl;
	cout << frac_a4 << " = " << (float)frac_a4 << endl;

	if( frac1 == frac2 )
		cout << "frac1 == frac2" << endl;
	if( frac1 != frac2 )
		cout << "frac1 != frac2" << endl;
	if( frac1 < frac2 )
		cout << "frac1 < frac2" << endl;
	if( frac1 > frac2 )
		cout << "frac1 > frac2" << endl;

	return 0;
}
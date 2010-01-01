// Assignment 2.7.8

#include <iostream>
using namespace std;

int main()
{
	int f_Array[10], min_Value, swap_Array;

	cout << "Enter ten array values..." << endl;
	for( int index = 0; index < 10; index++ )
	{
		cout << "f_Array[" << index << "] = ";
		cin >> f_Array[index];
	}

	cout << "Unsorted Array = { ";
	for( int index = 0; index < 10; index++ )
		cout << f_Array[index] << " ";
	cout << "}" << endl;
	
	for( int start_Index = 0; start_Index < 10; start_Index++ )
	{
		min_Value = start_Index;

		for( int current_Index = start_Index; current_Index < 10; current_Index++ )
		{
			if( f_Array[current_Index] < f_Array[min_Value] )
				min_Value = current_Index;
		}

		swap_Array = f_Array[min_Value];
		f_Array[min_Value] = f_Array[start_Index];
		f_Array[start_Index] = swap_Array;
	}

	cout << "  Sorted Array = { ";
	for( int index = 0; index < 10; index++ )
		cout << f_Array[index] << " ";
	cout << "}" << endl;

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Point3
{
public:
	// Constructors
	Point3();
	Point3( float x, float y, float z );
	
	// Data Members
	float mX;
	float mY;
	float mZ;
};

Point3::Point3()
{
	mX = 0.0f;
	mY = 0.0f;
	mZ = 0.0f;
}

Point3::Point3( float x, float y, float z )
{
	mX = x;
	mY = y;
	mZ = z;
}

int main()
{
	srand( time( 0 ) );
	
	int size = 0;
	while( true )
	{
		cout << "How many cubes to generate? ";
		cin >> size;
		if( size > 0 )
		{
			Point3 *cube = new Point3[size];

			for( int index = 0; index < size; index++ )
			{
				if( ( rand() % 2 ) == 1 )
					cube[index].mX = 1.0f;
				else
					cube[index].mX = -1.0f;

				if( ( rand() % 2 ) == 1 )
					cube[index].mY = 1.0f;
				else
					cube[index].mY = -1.0f;

				if( ( rand() % 2 ) == 1 )
					cube[index].mZ = 1.0f;
				else
					cube[index].mZ = -1.0f;
			}

			// Print Cubes
			cout << "Original Cubes:" << endl;
			for( int index = 0; index < size; index++ )
			{
				cout << "  cube[" << index << "] = (";
				if( cube[index].mX > 0 )
					cout << " ";
				cout << cube[index].mX << ",";
				if( cube[index].mY > 0 )
					cout << " ";
				cout << cube[index].mY << ",";
				if( cube[index].mZ > 0 )
					cout << " ";
				cout << cube[index].mZ << ")" << endl;
			}

			// Save Cubes to a file
			ofstream outFile( "pointdata.txt" );

			if( outFile )
			{
				outFile << hex;

				for( int index = 0; index < size; index++ )
					outFile << "cube[" << index << "] = " << cube[index].mX << ", "
					<< cube[index].mY << ", " << cube[index].mZ << endl;
			}

			outFile.close();

			// New Cubes
			Point3 *cube2 = new Point3[size];

			// Fill it
			for( int index = 0; index < size; index++ )
			{
				cube2[index].mX = 0.0f;
				cube2[index].mY = 0.0f;
				cube2[index].mZ = 0.0f;
			}

			// Print it
			cout << "New Cubes, before Loading:" << endl;
			for( int index = 0; index < size; index++ )
				cout << " cube2[" << index << "] = (" << cube2[index].mX << "," << cube2[index].mY << "," << cube2[index].mZ << ")" << endl;

			// Now load it back into memory
			ifstream inFile( "pointdata.txt" );

			if( inFile )
			{
				string garbage;
				inFile >> hex;
				for( int index = 0; index < size; index++ )
					inFile >> garbage >> garbage >> cube2[index].mX >> garbage
					>> cube2[index].mY >> garbage >> cube2[index].mZ;
			}

			inFile.close();
			
			// Print again
			cout << "New Cubes, after Loading:" << endl;
			for( int index = 0; index < size; index++ )
			{
				cout << " cube2[" << index << "] = (";
				if( cube2[index].mX > 0 )
					cout << " ";
				cout << cube2[index].mX << ",";
				if( cube2[index].mY > 0 )
					cout << " ";
				cout << cube2[index].mY << ",";
				if( cube2[index].mZ > 0 )
					cout << " ";
				cout << cube2[index].mZ << ")" << endl;
			}

			// Get rid of memory
			delete[] cube;
			cube = 0;
			delete[] cube2;
			cube2 = 0;

			break;
		}
	}

	return 0;
}
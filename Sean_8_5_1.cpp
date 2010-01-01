// Sean Gilleran
// 8.5.1 Line Count
// Sean_8_5_1.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename;
	cout << "Enter a filename: ";
	getline( cin, filename );

	ifstream inFile;
	inFile.open( filename.c_str() );

	if( inFile )
	{
		string garbage;
		int lineCount = 0;

		while( !inFile.eof() )
		{
			getline( inFile, garbage );
			cout << " :" << garbage << endl;
			lineCount++;
		}

		cout << endl;
		cout << "Line Count: " << lineCount << endl;
	}
	else
		cout << "File not found!" << endl;

	inFile.close();
	return 0;
}


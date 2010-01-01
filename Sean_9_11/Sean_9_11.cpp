// Sean Gilleran
// Employee Database
// Sean_9_11.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "s_Employee.h"
using namespace std;

void BubbleSort( vector<Employee*> &data ) // Copied from 3.7.8
{
	Employee* array_Swap = 0;

	// This is necessary to prevent the program from accessing
	// memory beyond the scope of the array

	int n = ( data.size() - 1 );

	// Run through the whole array and sort it piece by piece,
	// then, now that the largest number must necessarily be
	// at the end of the array, run through the array except
	// for the last element, then the second to last, etc.,
	// until the whole thing is sorted.

	for( int start_I = 0; start_I < n; start_I++ )
	{
		for( int cur_I = 0; cur_I < ( n - start_I ); cur_I++ )
		{
			if( data[cur_I]->mLastName > data[( cur_I + 1 )]->mLastName )
			{
				array_Swap = data[cur_I];
				data[cur_I] = data[( cur_I + 1 )];
				data[( cur_I + 1 )] = array_Swap;
			}
		}
	}
}

int main()
{
	// ***
	// .save() will save to this filename
	// ***
	const char* FILENAME = "database.txt";
	// ***

	// General Use
	int input = 1;
	
	// For searching/deleting
	string who = " ";
	char choice = 'N';
	bool found = false;

	// For loading
	string garbage = " ";

	// ***
	// NOTE in order for polymorphism to work properly, this MUST
	// be a vector of POINTERS, not of the class itself!
	// ***
	vector<Employee*> vec;
	// ***

	cout << "9.11 Employee Database" << endl;
	cout << "==========================" << endl;
	cout << endl;

	while( true )
	{
		while( true )
		{
			cout << "Main Menu" << endl;
			cout << " 1)View Database" << endl;
			cout << " 2)Add Employee" << endl;
			cout << " 3)Remove Employee" << endl;
			cout << " 4)Save to File" << endl;
			cout << " 5)Load from File" << endl;
			cout << " 6)Alphabetize Database" << endl;
			cout << " 7)Quit" << endl;
			cout << ">";
			cin >> input;
			cout << endl;

			if( input >= 1 && input <= 7 )
				break;
		}

		if( input == 1 ) // View Database
		{
			if( vec.size() > 0 ) // If there are elements in the database...
			{
				for( int index = 0; (unsigned)index < vec.size(); index++ )
				{
					vec[index]->print(); // Print them!
					cout << endl;
				}
			}
			else
			{
				cout << " No Entries!" << endl;
				cout << endl;
			}
		}
		else if( input == 2 ) // Add Employee
		{
			while( true )
			{
				cout << "Select Employee Type" << endl;
				cout << " 1)Manager" << endl;
				cout << " 2)Engineer" << endl;
				cout << " 3)Researcher" << endl;
				cout << " 4)Cancel" << endl;
				cout << ">";
				cin >> input;
				cout << endl;

				if( input >= 1 && input <= 4 )
					break;
			}

			if( input == 1 )
				vec.push_back( new Manager() );
			else if( input == 2 )
				vec.push_back( new Engineer() );
			else if( input == 3 )
				vec.push_back( new Researcher() );

			if( input != 4 ) // Don't ask for input unless there's a new addition
			{
				vec[ vec.size() - 1 ]->input();
				cout << endl;
			}
		}
		else if( input == 3 ) // Delete Employee
		{
			if( vec.size() > 0 )
			{
				cout << "Enter the last name of an Employee to remove" << endl;
				cout << ">";
				cin.get(); // I don't know why these are necessary but getline will eat up all
						   // the \n characters it can unless they're there
				getline( cin, who );
				cout << endl;
				
				for( int index = 0; (unsigned)index < vec.size(); index++ )
				{
					if ( vec[index]->mLastName == who )
					{
						found = true; // We've at least found the name, that's the first step

						while( true )
						{
							cout << "Erase " << vec[index]->mFirstName << " " << vec[index]->mLastName << ", "
								<< vec[index]->mCategory << "? (Y/N):"; // Make sure this is who we want
																		// to erase - this can also be
																		// used if we have multiple people
																		// with the same last name in order
																		// to sort through them.
							cin >> choice;

							if( choice == 'Y' || choice == 'y' )
							{
								vec.erase( vec.begin() + index );
								break;
							}
							else if( choice == 'N' || choice == 'n' )
								break;
						}
					}
				}

				if( !found )
					cout << "Employee not found!" << endl;
			}
			else
				cout << " No Entries!" << endl;
			cout << endl;
		}
		else if( input == 4 ) // Save Database
		{
			cout << "Saving to " << FILENAME << "..." << endl;
			if( vec.size() > 0 )
			{
				ofstream OutFile( FILENAME ); // Use the filename from the top of the file...

				if( OutFile )
				{
					for( int index = 0; (unsigned)index < vec.size(); index++ )
						vec[index]->save( OutFile );
					cout << " Saved to " << FILENAME << endl;
				}
				else
					cout << "ERR: Could not open " << FILENAME << endl;

				OutFile.close();

				cout << endl;
			}
			else
			{
				cout << " No Entries!" << endl;
				cout << endl;
			}
		}
		else if( input == 5 ) // Load from File
		{
			vec.clear(); // Get rid of current memory
			if( vec.size() == 0 )
			{
				cout << "Loading from " << FILENAME << "..." << endl;
				ifstream InFile( FILENAME );

				if( InFile )
				{
					while( !InFile.eof() )
					{
						InFile >> garbage;

						if( garbage == "Manager" )
							vec.push_back( new Manager() );
						else if( garbage == "Engineer" )
							vec.push_back( new Engineer() );
						else if( garbage == "Researcher" )
							vec.push_back( new Researcher() );
						else
							break;

						vec[ vec.size() - 1 ]->load( InFile );
					}

					cout << " Loaded from " << FILENAME << endl;
				}
				else
					cout << "ERR: Could not open " << FILENAME << endl;
				
				cout << endl;
				InFile.close();
			}
			else
				cout << "ERR: Could not clear memory" << endl;
		}
		else if( input == 6 ) // Sort Database
		{
			cout << "Sorting Database..." << endl;
			BubbleSort( vec );
			cout << " Database Sorted" << endl;
			cout << endl;
		}
		else if( input == 7 ) // Quit
			break;
	}

	return 0;

}
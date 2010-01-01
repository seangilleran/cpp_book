// Sean Gilleran
// Employee Database
// s_Employee.cpp

#include <iostream>
#include "s_Employee.h"
using namespace std;

Employee::Employee()
{
	mFirstName = "Default";
	mLastName = "Default";
	mCategory = "Employee";
	mSalary = 0;
}

Employee::Employee( const std::string &FirstName, const std::string &LastName,
				   int Salary )
{
	mFirstName = FirstName;
	mLastName = LastName;
	mCategory = "Employee";
	mSalary = Salary;
}

void Employee::print()
{
	cout << ":" << mLastName << ", " << mFirstName << endl;
	cout << " " << mCategory << endl;
	cout << " " << "Salary: $" << mSalary << ".00" << endl;
}

void Employee::input()
{
	cin.get();
	cout << "Enter First Name: ";
	getline( cin, mFirstName );
	cout << "Enter Last Name: ";
	getline( cin, mLastName );
	cout << "Enter Salary: ";
	cin >> mSalary;
}

void Employee::save( std::ofstream &OutFile )
{
	OutFile << endl;
	OutFile << mCategory << endl;
	OutFile << mLastName << " " << mFirstName << endl;
	OutFile << "Salary: " << mSalary << endl;
}

void Employee::load( std::ifstream &InFile )
{
	string garbage = " ";

	InFile >> mLastName >> mFirstName;
	InFile >> garbage >> mSalary;
}

Manager::Manager()
: Employee()
{
	mCategory = "Manager";
	mMeetings = 0;
	mVacation = 0;
}

Manager::Manager( const std::string &FirstName, const std::string &LastName,
				 int Salary, int MeetingsPerWeek, int VacationDays )
: Employee( FirstName, LastName, Salary )
{
	mCategory = "Manager";
	mMeetings = MeetingsPerWeek;
	mVacation = VacationDays;
}

void Manager::print()
{
	Employee::print();
	cout << " " << "Meetings per Week: " << mMeetings << endl;
	cout << " " << "Vacation Days: " << mVacation << endl;
}

void Manager::input()
{
	Employee::input();
	cout << "Enter # Meetings per Week: ";
	cin >> mMeetings;
	cout << "Enter # Vacation Days: ";
	cin >> mVacation;
}

void Manager::save( std::ofstream &OutFile )
{
	Employee::save( OutFile );
	OutFile << "Meetings: " << mMeetings << endl;
	OutFile << "Vacation: " << mVacation;
}

void Manager::load( std::ifstream &InFile )
{
	Employee::load( InFile );
	string garbage = " ";

	InFile >> garbage >> mMeetings;
	InFile >> garbage >> mVacation;
}

Engineer::Engineer()
: Employee()
{
	mCategory = "Engineer";
	mCPP = false;
	mYears = 0;
	mType = "Default";
}

Engineer::Engineer( const std::string &FirstName, const std::string &LastName,
				   int Salary, bool Cpp, int YearsXP, const std::string &Type )
: Employee( FirstName, LastName, Salary )
{
	mCategory = "Engineer";
	mCPP = Cpp;
	mYears = YearsXP;
	mType = Type;
}

void Engineer::print()
{
	Employee::print();
	if( mCPP )
		cout << " " << "Knows C++" << endl;
	else
		cout << " " << "Does not know C++" << endl;
	cout << " " << mYears << " years of Experience" << endl;
	cout << " " << mType << " Engineer" << endl;
}

void Engineer::input()
{
	Employee::input();

	char input = 'n';
	cout << "Knows C++? (Y/N): ";
	cin >> input;

	if( input == 'Y' || input == 'y' )
		mCPP = true;
	else
		mCPP = false;
	
	cout << "How many years experience? ";
	cin >> mYears;
	cin.get();
	cout << "What type of engineer? ";
	getline( cin, mType );
}

void Engineer::save( std::ofstream &OutFile )
{
	Employee::save( OutFile );
	OutFile << "CPP: ";
		if( mCPP )
			OutFile << "Yes" << endl;
		else
			OutFile << "No" << endl;
	OutFile << "Experience: " << mYears << endl;
	OutFile << "Type: " << mType;
}

void Engineer::load( std::ifstream &InFile )
{
	Employee::load( InFile );
	string garbage = " ";

	InFile >> garbage >> garbage;

	if( garbage == "Yes" )
		mCPP = true;
	else
		mCPP = false;

	InFile >> garbage >> mYears;
	InFile >> garbage >> mType;
}

Researcher::Researcher()
: Employee()
{
	mCategory = "Researcher";
	mSchool = "Default";
	mThesis = "Default";
}

Researcher::Researcher( const std::string &FirstName, const std::string &LastName,
					   int Salary, const std::string &School, const std::string &Thesis )
: Employee( FirstName, LastName, Salary )
{
	mCategory = "Researcher";
	mSchool = School;
	mThesis = Thesis;
}

void Researcher::print()
{
	Employee::print();
	cout << " " << "PhD from: " << mSchool << endl;
	cout << " " << "Thesis on: " << mThesis << endl;
}

void Researcher::input()
{
	Employee::input();
	cout << "PhD from? ";
	cin.get();
	getline( cin, mSchool );
	cout << "Thesis on? ";
	getline( cin, mThesis );
}

void Researcher::save( std::ofstream &OutFile )
{
	Employee::save( OutFile );
	OutFile << "School: " << mSchool << endl;
	OutFile << "Thesis: " << mThesis;
}

void Researcher::load( std::ifstream &InFile )
{
	Employee::load( InFile );
	string garbage = " ";

	InFile >> garbage >> mSchool;
	InFile >> garbage >> mThesis;
}
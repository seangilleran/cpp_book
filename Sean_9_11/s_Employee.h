// Sean Gilleran
// Employee Database
// s_Employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>

class Employee
{
public:
	// Constructors
	Employee();
	Employee( const std::string &FirstName, const std::string &LastName,
		int Salary );

	// Methods
	virtual void print();
	virtual void input();
	virtual void save( std::ofstream &OutFile );
	virtual void load( std::ifstream &InFile );

	// Data Members
	std::string mFirstName;
	std::string mLastName;
	std::string mCategory;
	int mSalary;
};

class Manager : public Employee
{
public:
	// Constructors
	Manager();
	Manager( const std::string &FirstName, const std::string &LastName,
		int Salary, int MeetingsPerWeek, int VacationDays );

	// Methods
	void print();
	void input();
	void save( std::ofstream &OutFile );
	void load( std::ifstream &InFile );

	// Data Members
	int mMeetings;
	int mVacation;
};

class Engineer : public Employee
{
public:
	// Constructors
	Engineer();
	Engineer( const std::string &FirstName, const std::string &LastName,
		int Salary, bool Cpp, int YearsXP, const std::string &Type );

	// Methods
	void print();
	void input();
	void save( std::ofstream &OutFile );
	void load( std::ifstream &InFile );

	// Data Members
	bool mCPP;
	int mYears;
	std::string mType;
};

class Researcher : public Employee
{
public:
	// Constructors
	Researcher();
	Researcher( const std::string &FirstName, const std::string &LastName,
		int Salary, const std::string &School, const std::string &Thesis );

	// Methods
	void print();
	void input();
	void save( std::ofstream &OutFile );
	void load( std::ifstream &InFile );

	// Data Members
	std::string mSchool;
	std::string mThesis;
};

#endif EMPLOYEE_H
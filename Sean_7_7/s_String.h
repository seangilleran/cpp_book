// Sean Gilleran
// Vector Class
// s_String.h

#ifndef S_STRING_H
#define S_STRING_H

class String
{
public:
	// Constructors
	String();
	String( const char *rhs );
	String( const String &rhs );

	// Methods
	String& operator = ( const String &rhs );
private:
	// Data Members
	char *mData;
};

#endif //S_STRING_H
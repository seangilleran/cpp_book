// Sean Gilleran
// 13.9.1 Linked List Class
// s_LinkedList.h

#ifndef S_LINKEDLIST_H
#define S_LINKEDLIST_H

template <class T>
struct LinkedNode
{
	// Constructor
	LinkedNode<T>( const T &input )
	{
		data = input;
		next = NULL;
		prev = NULL;
	}

	// Data Members
	T data;				// Stored Data
	LinkedNode *next;	// Next Node
	LinkedNode *prev;	// Previous Node
};

template <class T>
class LinkedList
{
public:
	// Constructors
	LinkedList();
	LinkedList( const LinkedList &rhs ) { *this = rhs; }
	~LinkedList();

	// Operators
	LinkedList<T>& operator =( const LinkedList<T> &rhs );
	LinkedNode<T>* operator[]( unsigned int index );

	// Methods
	bool empty()			{ return mFirst == NULL; }
	unsigned int size()		{ return mSize; }
	
	LinkedNode<T>* find( const T &data ); // Retrieve Methods
	LinkedNode<T>* first()	{ return mFirst; }
	LinkedNode<T>* last()	{ return mLast; }

	void push_first ( const T &data );	// Push methods
	void push_last  ( const T &data );
	bool push_after ( const T &data, const T &key );
	bool push_before( const T &data, const T &key );

	void pop_first();					// Pop methods
	void pop_last();
	bool pop_value( const T &key );
	void erase();

private:
	// Data Members
	LinkedNode<T> *mFirst;
	LinkedNode<T> *mLast;

	unsigned int mSize;
};


//  Constructors
// --------------------

template <class T>
LinkedList<T>::LinkedList()
{
	mFirst = NULL;
	mLast = NULL;
	mSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	erase();
}


//  Operators
// --------------------

template <class T>
LinkedList<T>& LinkedList<T>::operator=( const LinkedList<T> &rhs )
{
	mFirst = rhs.mFirst;
	mLast = rhs.mLast;
	mSize = rhs.mSize;
}

template <class T>
LinkedNode<T>* LinkedList<T>::operator[]( unsigned int index )
{
	LinkedNode<T> *current = mFirst;

	for( unsigned int count = 0; count < index; count++ )
		current = current->next;

	return current;
}


//  Retrieve Methods
// --------------------

template <class T>	// Return NULL pointer if data not found
LinkedNode<T>* LinkedList<T>::find( const T &data )
{
	if( !empty() )	// List is not empty
	{
		LinkedNode<T> *current = mFirst;

		while( current->data != data )
		{
			current = current->next;
			if ( current == NULL )
				return NULL;
		}

		return current;
	}
	else			// List is empty
		return NULL;
}


//  Push Methods
// --------------------

template <class T>
void LinkedList<T>::push_first( const T &data )
{
	LinkedNode<T> *newFirst = new LinkedNode<T>( data );
	
	if( !empty() )	// List is not empty
	{
		newFirst->prev = NULL;
		newFirst->next = mFirst;
		mFirst->prev = newFirst;

		mFirst = newFirst;
	}
	else			// List is empty
	{
		newFirst->next = NULL;
		newFirst->prev = NULL;

		mFirst = newFirst;
		mLast = newFirst;
	}

	mSize++;
}

template <class T>
void LinkedList<T>::push_last( const T &data )
{
	LinkedNode<T> *newLast = new LinkedNode<T>( data );

	if( !empty() )	// List is not empty
	{
		newLast->next = NULL;
		newLast->prev = mLast;
		mLast->next = newLast;

		mLast = newLast;
	}
	else			// List is empty
	{
		newLast->next = NULL;
		newLast->prev = NULL;

		mLast = newLast;
		mFirst = newLast;
	}

	mSize++;
}

template <class T>	// true if the key is found, false if unsuccessful
bool LinkedList<T>::push_after( const T &data, const T &key )
{
	if( !empty() )	// List is not empty
	{
		LinkedNode<T> *current = mFirst;

		while( current->data != key )
		{
			current = current->next;
			if( current == NULL )	// Reached the end and didn't find it
				return false;
		}

		LinkedNode<T> *newNode = new LinkedNode<T>( data );

		if( current!= mLast )	// Current node is not last
		{
			newNode->next = current->next;
			newNode->prev = current;

			current->next->prev = newNode;
			current->next = newNode;

			mSize++;
		}
		else					// Current node is last
			push_last( data );

		return true;
	}
	else			// List is empty
		return false;
}

template <class T>	// true if the key is found, false if unsuccessful
bool LinkedList<T>::push_before( const T &data, const T &key )
{
	if( !empty() )	// List is not empty
	{
		LinkedNode<T> *current = mFirst;

		while( current->data != key )
		{
			current = current->next;
			if( current == NULL )	// Reached the end and didn't find it
				return false;
		}

		LinkedNode<T> *newNode = new LinkedNode<T>( data );

		if( current!= mFirst )	// Current node is not first
		{
			newNode->prev = current->prev;
			newNode->next = current;

			current->prev->next = newNode;
			current->prev = newNode;

			mSize++;
		}
		else					// Current node is first
			push_first( data );

		return true;
	}
	else			// List is empty
		return false;
}


//  Pop Methods
// --------------------

template <class T>
void LinkedList<T>::pop_first()
{
	if( mSize > 1 )	// mFirst is not the only element
	{
		LinkedNode<T> *newFirst = mFirst->next;

		delete mFirst;

		newFirst->prev = NULL;
		mFirst = newFirst;

		mSize--;
	}
	else 
		erase();
}

template <class T>
void LinkedList<T>::pop_last()
{
	if( mSize > 1 )	// mLast is not the only element
	{
		LinkedNode<T> *newLast = mLast->prev;

		delete mLast;

		newLast->next = NULL;
		mLast = newLast;

		mSize--;
	}
	else
		erase();
}

template <class T>	// true if the key is found, false if unsuccessful
bool LinkedList<T>::pop_value( const T &key )
{
	if( !empty() )	// List is not empty
	{
		LinkedNode<T> *current = mFirst;

		while( current->data != key )
		{
			current = current->next;
			if( current == NULL )
				return false;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;

		delete current;
		current = NULL;

		mSize--;

		return true;
	}
	else			// List is empty
		return false;
}

template <class T>
void LinkedList<T>::erase()
{
	if( !empty() )
	{
		LinkedNode<T> *current = mFirst;

		while( current != NULL )
		{
			LinkedNode<T> *oldNode = current;
			current = current->next;
			
			delete oldNode;
			oldNode = NULL;

			mSize--;
		}

		delete current;
		current = NULL;

		mFirst = NULL;
		mLast = NULL;
	}
}

#endif //S_LINKEDLIST_H
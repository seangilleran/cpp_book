// Sean Gilleran
// 10.5.1 Array Class
// s_Array.h

#ifndef ARRAY_H
#define ARRAY_H

// ********************
//  Class Definition
// ********************

template <class T>
class Array
{
public:
	// Constructors
	Array();
	Array( int numElements );
	Array( const Array &rhs );
	~Array();

	// Operators
	T& operator []( int index );
	T& operator =( const Array &rhs );

	// Methods
	int size();
	void resize( int newSize );

	void push( const T &rhs );
	void pop();

private:
	void destroy();

	// Data Members
	int mSize;
	T *mData;
};

// ********************
//  Constructors
// ********************

template <class T>
Array<T>::Array()
{
	mSize = 0;
	mData = new T;
}

template <class T>
Array<T>::Array( int numElements )
{
	mSize = numElements;
	mData = new T[mSize];
}

template <class T>
Array<T>::Array( const Array<T> &rhs )
{
	mSize = rhs.mSize;
	mData = new T[mSize];

	for( int index = 0; index < mSize; index++ )
		mData[index] = rhs.mData[index];
}

template <class T>
Array<T>::~Array()
{
	destroy();
}

// ********************
//  Operators
// ********************

template <class T>
T& Array<T>::operator [](int index)
{
	return mData[index];
}

template <class T>
T& Array<T>::operator =( const Array &rhs )
{
	if( this != &rhs )
	{
		destroy();

		mSize = rhs.mSize;
		mData = new T[mSize];

		for( int index = 0; index < mSize; index++ )
			mData[index] = rhs.mData[index];
	}

	return *this;
}

// ********************
//  Methods
// ********************

template <class T>
int Array<T>::size()
{
	return mSize;
}

template <class T>
void Array<T>::resize( int newSize )
{
	if( newSize != mSize )
	{
		T *temp = new T[mSize]; // Copy old data
		for( int index = 0; index < mSize; index++ )
			temp[index] = mData[index];

		destroy(); // Reset
		mData = new T[newSize];

		if( newSize > mSize ) // Is it bigger?
			for( int index = 0; index < mSize; index++ )
				mData[index] = temp[index];
		else if( newSize < mSize ) // Or smaller?
			for( int index = 0; index < newSize; index++ )
				mData[index] = temp[index];

		delete[] temp;
		temp = NULL;

		mSize = newSize;
	}
}

template <class T>
void Array<T>::push( const T &rhs )
{
	resize( mSize + 1 );
	mData[mSize - 1] = rhs;
}

template <class T>
void Array<T>::pop()
{
	resize( mSize - 1 );
}

template <class T>
void Array<T>::destroy()
{
	delete[] mData;
	mData = NULL;
}

#endif //ARRAY_H
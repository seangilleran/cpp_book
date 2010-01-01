// Sean Gilleran
// 10.5.3 Table Driver
// s_Table.h

#ifndef TABLE_H
#define TABLE_H

template <typename T>
class Table
{
public:
	// Constructors
	Table();
	Table( int m, int n );
	Table( int m, int n, const T &value );
	Table( const Table<T> &rhs );
	~Table();

	// Operators
	Table<T>& operator =( const Table &rhs );
	T& operator ()( int i, int j );

	// Methods
	int nRows() const;
	int nCols() const;

	void resize( int m, int n );
	void resize( int m, int n, const T &value );

private:
	void destroy();

	int mRows, mCols;
	T** mData;
};

// ********************
//  Constructors
// ********************

template <typename T>
Table<T>::Table()
{
	mData = 0;
	mRows = 0;
	mCols = 0;
}

template <typename T>
Table<T>::Table( int m, int n )
{
	mData = 0;
	mRows = 0;
	mCols = 0;
	resize( m, n, T() );
}

template <typename T>
Table<T>::Table( int m, int n, const T &value )
{
	mData = 0;
	mRows = 0;
	mCols = 0;
	resize( m, n, value );
}

template <typename T>
Table<T>::Table( const Table<T> &rhs )
{
	mData = 0;
	mRows = 0;
	mCols = 0;
	*this = rhs;
}

template <typename T>
Table<T>::~Table()
{
	destroy();
}

// ********************
//  Operators
// ********************

template <typename T>
Table<T>& Table<T>::operator =( const Table &rhs )
{
	if( *this == rhs ) return *this;

	resize( rhs.mRows, rhs.mCols );

	for( int i = 0; i < mRows; ++i )
		for( int j = 0; j < mCols; ++j )
			mData[i][j] = rhs.mData[i][j];

	return *this;
}

template <typename T>
T& Table<T>::operator ()( int i, int j )
{
	return mData[i][j];
}

// ********************
//  Methods
// ********************

template <typename T>
int Table<T>::nRows() const
{
	return mRows;
}

template <typename T>
int Table<T>::nCols() const
{
	return mCols;
}

template <typename T>
void Table<T>::resize( int m, int n )
{
	resize( m, n, T() );
}

template <typename T>
void Table<T>::resize( int m, int n, const T &value )
{
	destroy();

	mRows = m;
	mCols = n;

	mData = new T*[mRows];
	for( int i = 0; i < mRows; ++i )
	{
		mData[i] = new T[mCols];
		for( int j = 0; j < mCols; ++j )
			mData[i][j] = value;
	}
}

template <typename T>
void Table<T>::destroy()
{
	for( int i = 0; i < mRows; ++i )
	{
		delete[] mData[i];
		mData[i] = NULL;
	}

	delete[] mData;
	mData = NULL;

	mRows = 0;
	mCols = 0;
}

#endif //TABLE_H
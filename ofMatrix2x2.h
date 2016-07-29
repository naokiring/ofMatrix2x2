#pragma once

#include "ofConstants.h"

/// Based on ofMatrix2x2

/// \brief A 2x2 Matrix
///
/// The layout is like this:
///
///     [ a b ]
///     [ c d ]

class ofMatrix2x2 {
	
	
public:
	
	float a;
	float b;
	float c;
	float d;

	
	
	
	//---------------------
	/// \name Constructor
	/// \{
	
	ofMatrix2x2( float _a=0.0, float _b=0.0,
                float _c=0.0, float _d=0.0 );
	
	
	/// \}
	
	//---------------------
	/// \name Matrix access
	/// \{
	
	void set( float _a, float _b,
             float _c, float _d );
	
	
	float& operator[]( const int& index );

	
	/// \}
	
	//---------------------
	/// \name Functions
	/// \{
	
	
	/// \brief Transpose the matrix
	///
	/// This changes the matrix.
	///
	///     [ a b ]T    [ a c ]
	///     [ c d ]  =  [ b d ]
	void transpose();
		
	/// \brief Transpose without changing the matrix.
	/// Uses the "swap" method with additions and subtractions to swap the elements that aren't on the main diagonal.
	/// \returns transposed matrix.	
	ofMatrix2x2 transpose(const ofMatrix2x2& A);
	
	/// \brief Find the determinant of the matrix
	/// \sa [Wolfram explanation](http://mathworld.wolfram.com/Determinant.html)
	float determinant() const;
	
	float determinant(const ofMatrix2x2& A);
	
	
	
	
	/// \brief Inverse of a 2x2 matrix
	///
	/// the inverse is the adjoint divided through the determinant
	/// find the matrix of minors (minor = determinant of 2x2 matrix of the 2 rows/colums current element is NOT in)
	/// turn them in cofactors (= change some of the signs)
	/// find the adjoint by transposing the matrix of cofactors
	/// divide this through the determinant to get the inverse
	///
	/// \sa invert();	
	ofMatrix2x2 inverse(const ofMatrix2x2& A);
	
	void invert();
	
	
	/// \brief Multiply a matrix by a matrix entry by entry (i.e. a*a, b*b, c*c...)
	///
	/// This is referred to as an entrywise, Hadamard, or Schur product.
	ofMatrix2x2 entrywiseTimes(const ofMatrix2x2& A);

	/// \}
	
	//---------------------
	/// \name Operators
	/// \{
	

	
	/// \brief Add two matrices
	ofMatrix2x2 operator+(const ofMatrix2x2& B);
	
	/// \brief Add matrix to existing matrix
	void operator+=(const ofMatrix2x2& B);
	
	/// \brief Subtract two matrices
	ofMatrix2x2 operator-(const ofMatrix2x2& B);
	
	/// \brief Subtract matrix from existing matrix
	void operator-=(const ofMatrix2x2& B);
	
	/// \brief Multiply a matrix with a scalar		
	ofMatrix2x2 operator*(float scalar);
	
	/// \brief Multiply a matrix by a matrix this = this*B (in that order)	 
	void operator*=(const ofMatrix2x2& B);
	
	/// \brief Multiply a matrix by a scalar (multiples all entries by scalar)	 
	void operator*=(float scalar);
	
	/// \brief Multiply a 3x3 matrix with a 3x3 matrix	 
	ofMatrix2x2 operator*(const ofMatrix2x2& B);
	
	/// \brief Divide a matrix through a scalar		
	ofMatrix2x2 operator/(float scalar);
	
	void operator/=(const ofMatrix2x2& B);
	
	void operator/=(float scalar);
	
	friend ostream& operator<<(ostream& os, const ofMatrix2x2& M);
	friend istream& operator>>(istream& is, ofMatrix2x2& M);
	
	/// \}
};


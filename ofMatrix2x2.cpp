#include "ofMatrix2x2.h"

ofMatrix2x2::ofMatrix2x2( float _a, float _b,
                         float _c, float _d )
{
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}




void ofMatrix2x2::set( float _a, float _b,
                      float _c, float _d )
{
	a = _a;
	b = _b;
	c = _c;
	d = _d;
}


float& ofMatrix2x2::operator[]( const int& index ) {
	switch(index) {
		case 0:  return a;
		case 1:  return b;
		case 2:  return c;
		case 3:  return d;
		default: return a;
	}
}


/*
 * Transpose:
 * This changes the matrix.
 * [ a b ]T    [ a c ]
 * [ c d ]  =  [ b d ]
 */

void ofMatrix2x2::transpose() {
	b += c; c = b - c; b -= c; //swap b and c
}

/*
* Transpose without changing the matrix.
* Uses the "swap" method with additions and subtractions to swap the elements that aren't on the main diagonal.
* @return transposed matrix.
*/

ofMatrix2x2 ofMatrix2x2::transpose(const ofMatrix2x2& A) {
	ofMatrix2x2 result = A;
	result.transpose();
	return result;
}



/*
* Determinant: http://mathworld.wolfram.com/Determinant.html
*/

float ofMatrix2x2::determinant() const {
	float det = a * d - b * c;
	return det;
}

float ofMatrix2x2::determinant(const ofMatrix2x2& A) {
	return A.determinant();
}



/*
* Inverse of a 2x2 matrix
  the inverse is the adjoint divided through the determinant
  find the matrix of minors (minor = determinant of 2x2 matrix of the 2 rows/colums current element is NOT in)
  turn them in cofactors (= change some of the signs)
  find the adjoint by transposing the matrix of cofactors
  divide this through the determinant to get the inverse
*/

void ofMatrix2x2::invert() {
	 float det = determinant();
	 ofMatrix2x2 B;

	 //included in these calculations: minor, cofactor (changed signs), transpose (by the order of "="), division through determinant
	 B.a = d / det;
	 B.b = -b / det;
	 B.c = -c / det;
	 B.d = a / det;

	 *this = B;
}

ofMatrix2x2 ofMatrix2x2::inverse(const ofMatrix2x2& A) {
	ofMatrix2x2 result = A;
	result.invert();
	return result;
}



/*
* Add two matrices
*/
ofMatrix2x2 ofMatrix2x2::operator+(const ofMatrix2x2& B) {
	ofMatrix2x2 result;
	result.a = a + B.a;
	result.b = b + B.b;
	result.c = c + B.c;
	result.d = d + B.d;
	return result;
}

void ofMatrix2x2::operator+=(const ofMatrix2x2& B) {
	a += B.a;
	b += B.b;
	c += B.c;
	d += B.d;
}

/*
* Subtract two matrices
*/
ofMatrix2x2 ofMatrix2x2::operator-(const ofMatrix2x2& B) {
	ofMatrix2x2 result;
	result.a = a - B.a;
	result.b = b - B.b;
	result.c = c - B.c;
	result.d = d - B.d;
	return result;
}

void ofMatrix2x2::operator-=(const ofMatrix2x2& B) {
	a -= B.a;
	b -= B.b;
	c -= B.c;
	d -= B.d;
}


/*
* Multiply a matrix with a scalar
*/
ofMatrix2x2 ofMatrix2x2::operator*(float scalar) {
	ofMatrix2x2 result;
	result.a = a * scalar;
	result.b = b * scalar;
	result.c = c * scalar;
	result.d = d * scalar;
	return result;
}


void ofMatrix2x2::operator*=(const ofMatrix2x2& B) {
  *this = *this*B;
}

ofMatrix2x2 ofMatrix2x2::entrywiseTimes(const ofMatrix2x2& B){
  ofMatrix2x2 C = *this;
	C.a *= B.a;
	C.b *= B.b;
	C.c *= B.c;
	C.d *= B.d;
  return C;
}

void ofMatrix2x2::operator*=(float scalar) {
	a *= scalar;
	b *= scalar;
	c *= scalar;
	d *= scalar;
}

 /*
 * Multiply a 2x2 matrix with a 2x2 matrix
 */
ofMatrix2x2 ofMatrix2x2::operator*(const ofMatrix2x2& B) {
	ofMatrix2x2 C;
	C.a = a * B.a + b * B.c;
	C.b = a * B.b + b * B.d;
	C.c = c * B.a + d * B.c;
	C.d = c * B.b + d * B.d;
	return C;
}

/*
* Divide a matrix through a scalar
*/
ofMatrix2x2 ofMatrix2x2::operator/(float scalar) {
	ofMatrix2x2 result;
	result.a = a / scalar;
	result.b = b / scalar;
	result.c = c / scalar;
	result.d = d / scalar;
	return result;
}


void ofMatrix2x2::operator/=(const ofMatrix2x2& B) {
	a /= B.a;
	b /= B.b;
	c /= B.c;
	d /= B.d;
}

void ofMatrix2x2::operator/=(float scalar) {
	a /= scalar;
	b /= scalar;
	c /= scalar;
	d /= scalar;
}


ostream& operator<<(ostream& os, const ofMatrix2x2& M) {
	int w = 8;
	os	<< setw(w)
		<< M.a << ", " << setw(w)
		<< M.b << std::endl;

	os	<< setw(w)
		<< M.c << ", " << setw(w)
		<< M.d << std::endl;

	return os;
}

istream& operator>>(istream& is, ofMatrix2x2& M) {
	is >> M.a; is.ignore(2);
	is >> M.b; is.ignore(1);
	is >> M.c; is.ignore(2);
	is >> M.d;
	return is;
}


ofVec2f ofMatrix2x2::operator*(const ofVec2f& v) {
	ofVec2f ret;
	ret.x = a * v.x + b * v.y;
    ret.y = c * v.x + d * v.y;
	return ret;
}

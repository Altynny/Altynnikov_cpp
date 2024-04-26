#pragma once
#include <istream>
using namespace std;

class Rational {
	int numer, denom;
	void simplify();
public:
	//__Конструкторы__
	Rational();							// по умолчанию
	Rational(int _numer);				// с одним числом
	Rational(int _numer, int _denom);	// с двумя числами

	//__Операторы__
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;

	Rational operator -() const;
	Rational& operator -=(const Rational& r);
	Rational operator -(const Rational& r) const;

	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;

	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r) const;
	
	Rational& operator ++();   // префикс
	Rational operator ++(int); // постфикс

	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;

	operator int() const;
	operator double() const;

	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);
};
#pragma once
#include <istream>
using namespace std;

class Rational {
	int numer, denom;
	void simplify();
public:
	//__������������__
	Rational();							// �� ���������
	Rational(int _numer);				// � ����� ������
	Rational(int _numer, int _denom);	// � ����� �������

	//__���������__
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;

	Rational operator -() const;
	Rational& operator -=(const Rational& r);
	Rational operator -(const Rational& r) const;

	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;

	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r) const;
	
	Rational& operator ++();   // �������
	Rational operator ++(int); // ��������

	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;

	operator int() const;
	operator double() const;

	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);
};
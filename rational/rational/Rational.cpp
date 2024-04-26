#include "Rational.h"
using namespace std;

void Rational::simplify() {
	if (denom < 0) {
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0) {
			numer /= i;
			denom /= i;
			i--;
		}
}

//____������������____
Rational::Rational() {
	numer = 0;
	denom = 1;
}

Rational::Rational(int _numer) {
	numer = _numer;
	denom = 1;
}

Rational::Rational(int _numer, int _denom) {
	if (_denom == 0)
		throw("����������� �� ����� ���� ����� ����");
    numer = _numer;
    denom = _denom;
	simplify();
}

//____���������____
Rational& Rational::operator +=(const Rational& r) {
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	// this - ��������� �� ����
	// *this - ������ �� ����
	simplify();
	return *this;
}

Rational Rational::operator +(const Rational& r) const {
	Rational res(*this);
	// ���������� ������� �������� ����������
	return res += r;
}


Rational Rational::operator -() const {
	Rational r(-numer, denom);
	return r;
}

Rational& Rational::operator -=(const Rational& r) {
	return (*this += (-r));
}

Rational Rational::operator -(const Rational& r) const {
	Rational res(*this);
	return res -= r;
}


Rational& Rational::operator *=(const Rational& r) {
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator *(const Rational& r) const {
	Rational res(*this);
	return res *= r;
}


Rational& Rational::operator /=(const Rational& r) {
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}

Rational Rational::operator /(const Rational& r) const {
	Rational res(*this);
	return res /= r;
}


Rational& Rational::operator ++() {
	numer += denom;
	return *this;
}

Rational Rational::operator ++(int) {
	Rational r(*this);
	numer += denom;
	return r;
}


bool Rational::operator ==(const Rational& r) const {
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const {
	return !(*this == r);
}


Rational::operator int() const {
	return numer / denom;
}

Rational::operator double() const {
	return ((double)numer) / denom;
}


istream& operator >>(istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	return in;
}

ostream& operator <<(ostream& out, const Rational& r) {
	out << r.numer << "/" << r.denom;
	return out;
}
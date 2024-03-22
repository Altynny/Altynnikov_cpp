#include "DateTime.h"
#include "DateFunctions.h"

using namespace std;

// конструкторы
DateTime::DateTime() 
{
	year = 0;
	month = 1;
	day = 1;
}

DateTime::DateTime(int _year, int _month, int _day)
{
	if (_month < 1 || _month > 12)
		throw "Incorrect month";
	
	year = _year;
	month = _month;
	day = _day;
}

// операторы
int DateTime::operator -(const DateTime& d) const
{
	return unixtime_to_julian(year, month, day) - unixtime_to_julian(d.year, d.month, d.day);
}

istream& operator >>(istream& in, DateTime& d)
{
	in >> d.year >> d.month >> d.day;
	return in;
}

ostream& operator <<(ostream& out, const DateTime& d)
{
	out << d.year << '.' << d.month << '.' << d.day;
	return out;
}
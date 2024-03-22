#pragma once
#include <iostream>
using namespace std;

class DateTime 
{
	int year, month, day;
public:
	// конструкторы
	DateTime();
	DateTime(int _year, int _month, int _day);
	// операторы
	int operator -(const DateTime& d) const;
	//DateTime& operator +(const int& days);
	friend istream& operator >>(istream& in, DateTime& d);
	friend ostream& operator <<(ostream& in, const DateTime& d);
};
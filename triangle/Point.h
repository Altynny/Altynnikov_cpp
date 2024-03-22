#pragma once
#include <iostream>
using namespace std;

class Point {
public:
	double x, y;
	Point();
	Point(double _x, double _y);
};

istream& operator >>(istream& in, Point& p);
ostream& operator <<(ostream& out, const Point& p);
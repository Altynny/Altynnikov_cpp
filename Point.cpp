#include "Point.h"

Point::Point() {
	x = y = 0.0;
}

Point::Point(double _x, double _y) {
	x = _x;
	y = _y;
}

istream& operator >>(istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

ostream& operator <<(ostream& out, const Point& p) {
	out << p.x << ' ' << p.y;
	return out;
}
#include "Triangle.h"
#include "Geometry.h"

Triangle::Triangle() {
	area = 0.0;
}

Triangle::Triangle(Point _a, Point _b, Point _c) {
	a = _a;
	b = _b;
	c = _c;
	ab = Segment(_a, _b);
	bc = Segment(_b, _c);
	ac = Segment(_a, _c);
	area = areaBySeg(ab, bc, ac);
}
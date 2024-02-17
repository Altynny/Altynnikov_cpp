#include "Segment.h"
#include "Geometry.h"

Segment::Segment() {
	length = 0.0;
}

Segment::Segment(Point _a, Point _b) {
	a = _a;
	b = _b;
	length = distance(_a, _b);
}
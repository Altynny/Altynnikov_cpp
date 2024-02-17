#pragma once
#include "Point.h"

class Segment {
public:
	Point a, b;
	double length;
	Segment();
	Segment(Point _a, Point _b);
};
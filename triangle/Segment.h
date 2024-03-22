#pragma once
#include "Point.h"

class Segment {
public:
	Point a, b; //координаты начала и конца
	double length; //длина
	Segment();
	Segment(Point _a, Point _b);
};
#pragma once
#include "Point.h"
#include "Segment.h"

class Triangle {
public:
	Point a, b, c; //�������
	Segment ab, bc, ac; //�������
	double area; //�������
	Triangle();
	Triangle(Point _a, Point _b, Point _c);
};
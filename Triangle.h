#pragma once
#include "Point.h"
#include "Segment.h"

class Triangle {
public:
	Point a, b, c; //вершины
	Segment ab, bc, ac; //стороны
	double area; //площадь
	Triangle();
	Triangle(Point _a, Point _b, Point _c);
};
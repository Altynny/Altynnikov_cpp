#pragma once
#include "Point.h"
#include "Segment.h"
#include <iostream>
using namespace std;

class Triangle {
public:
	Point a, b, c; //вершины
	Segment ab, bc, ac; //стороны
	double area; //площадь
	Triangle();
	Triangle(Point _a, Point _b, Point _c);
	bool operator >(const Triangle& tr);
};

ostream& operator <<(ostream& out, const Triangle& tr);
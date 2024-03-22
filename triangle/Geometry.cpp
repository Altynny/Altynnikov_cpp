#include "Geometry.h"
#include <math.h>
//расстояние по теореме Пифагора
double distance(const Point& p1, const Point& p2) {
	return sqrt((p1.x - p2.x)* (p1.x - p2.x)+ (p1.y - p2.y) * (p1.y - p2.y));
}

//высчитывание площади по формуле Герона
double areaBySeg(const Segment& a, const Segment& b, const Segment& c) { 
	double p2 = (a.length + b.length + c.length) / 2.0; //полупериметр по длине сторон
	if (p2 <= 0.0 || p2 <= a.length || p2 <= b.length || p2 <= c.length)
		return 0.0;
	return sqrt(p2 * (p2 - a.length) * (p2 - b.length) * (p2 - c.length));
}
#pragma once
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

// __Абстрактный класс фигур__
class GeometricFigure
{
public:
	virtual double calc_area()=0;
	virtual double calc_perimeter()=0;
	virtual string name()=0;
};


// __Круг__
template <class P, class R> class Circle: public GeometricFigure
{
protected:
	string f_name = "Circle";
	P center;
	R radius;
public:
	Circle();
	Circle(P _center, R _radius);
	double calc_area();
	double calc_perimeter();
	string name();
};

// __функции круга__
template <class P, class R> Circle<P, R>::Circle()
{
	center = {0, 0};
	radius = 1;
}

template <class P, class R> Circle<P, R>::Circle(P _center, R _radius)
{
	center = _center;
	radius = _radius;
}

template <class P, class R> double Circle<P, R>::calc_area()
{
	return M_PI * (radius * radius);
}

template <class P, class R> double Circle<P, R>::calc_perimeter()
{
	return M_PI * (2 * radius);
}

template <class P, class R> string Circle<P, R>::name()
{
	return f_name;
}

// __Эллипс__
template <class P, class R> class Ellipse : public GeometricFigure
{
protected:
	string f_name = "Ellipse";
	P center;
	R radius1;
	R radius2;
public:
	Ellipse();
	Ellipse(P _center, R _radius1, R _radius2);
	double calc_area();
	double calc_perimeter();
	string name();
};

// __функции элллипса__
template <class P, class R> Ellipse<P, R>::Ellipse()
{
	center = { 0, 0 };
	radius1 = 1;
	radius2 = 1;
}

template <class P, class R> Ellipse<P, R>::Ellipse(P _center, R _radius1, R _radius2)
{
	center = _center;
	radius1 = _radius1;
	radius2 = _radius2;
}

template <class P, class R> double Ellipse<P, R>::calc_area()
{
	return M_PI * (radius1 * radius2);
}

template <class P, class R> double Ellipse<P, R>::calc_perimeter()
{
	return M_PI * (2 * sqrt((radius1 * radius1 + radius2 * radius2) / 2));
}

template <class P, class R> string Ellipse<P, R>::name()
{
	return f_name;
}


//// __Прямоугольник__
//template <class P> class Rectangle : public GeometricFigure
//{
//protected:
//	string f_name = "Rectangle";
//	P points;
//public:
//	Rectangle();
//	Rectangle(P _points);
//	double calc_area();
//	double calc_perimeter();
//	string name();
//};
//
//// __функции многоугольника__
//template <class P> Rectangle<P>::Rectangle()
//{
//	points = 0;
//}
//
//template <class P> Rectangle<P>::Rectangle(P _points)
//{
//	points = _points;
//}
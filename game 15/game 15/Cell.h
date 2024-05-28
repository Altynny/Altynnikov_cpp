#pragma once
#include <ostream>

using namespace std;

class CellException{};
struct Cell
{
	int number;
	int x, y;
	Cell();
	Cell(int _x, int _y, int _n = 0);
	void set_number(int _n) { number = _n; };
	friend ostream& operator <<(ostream& out, const Cell& cell);
};
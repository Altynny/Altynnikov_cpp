#include "Cell.h"

Cell::Cell()
{
	x = 0;
	y = 0;
	number = 0;
}

Cell::Cell(int _x, int _y, int _n)
{
	if (_x < 0 || _y < 0)
		throw CellException();
	x = _x;
	y = _y;
	number = _n;
}

ostream& operator <<(ostream& out, const Cell& cell)
{
	int n = cell.number;
	if (n == 0) out << '|' << "  " << '|';
	else out <<'|' << n << '|';
	return out;
}
#include "Box.h"
#include <ctime>

// Проверка на решаемость
bool Box::isSolvable()
{
	// находим число инверсий
	int inversions = 0;
	for (int i = 0; i < width; ++i)
		for (int j = 0; j < width; ++j)
		{
			int verifiable = cells[i][j].number;
			if (verifiable == 0) continue;
			int l = j + 1;
			for (int k = i; k < width; ++k)
			{
				for (l; l < width; ++l)
				{
					int to_verify = cells[k][l].number;
					if (to_verify != 0 && verifiable > to_verify)
						++inversions;
				}
				l = 0;
			}
		}
	//
	//	1) чётная ширина поля:
	//		чётная ширина и нечётное число инверсий - поле решаемо (иначе нет)
	//		нечётная ширина и чётное число инверсий - поле решаемо (иначе нет)
	//	2) нечётная ширина поля:
	//		чётное число инверсий - поле решаемо(иначе нет)
	//
	bool even_inv = inversions % 2 == 0 ? true:false;
	if (width % 2 == 0)
	{
		int row_num = width - null_cell->y;
		bool even_row = row_num % 2 == 0 ? true : false;
		if (even_inv)
			return even_row == false ? true : false;
		else 
			return even_row == true ? true : false;
	}
	else if (even_inv)
		return true;

	return false;
}

// Конструктор
Box::Box(int _width)
{
	width = _width;
	int box_size = width * width;
	
	// cоздаём массив с цифрами клеток в случайном порядке
	srand(time(0));
	int* rand_numbers = new int[box_size] {0};
	for (int i = 0; i < box_size; ++i)
	{
		int j = rand() % (i + 1);
		rand_numbers[i] = rand_numbers[j];
		rand_numbers[j] = i;
	}

	// cоздаём динамический массив для хранения клеток
	cells = new Cell * [width];
	for (int i = 0; i < width; ++i)
		cells[i] = new Cell[width];

	// заполняем массив клеток объектами со значениями и координатами
	Cell* max1 = null_cell; //  
	Cell* max2 = null_cell; // максимумы для случая нерешаемости
	for (int i = 0; i < box_size; ++i)
	{
		int y = i / width;
		int x = i % width;
		int n = rand_numbers[i];
		cells[y][x] = Cell(x, y, n);
		if (n == 0)
			null_cell = &cells[y][x];

		if (n == box_size - 1)
			max1 = &cells[y][x];

		if (n == box_size - 2)
			max2 = &cells[y][x];
	}
	
	if (!isSolvable())
	{
		max1->number = box_size - 2;
		max2->number = box_size - 1;
	}

	// больше массив с цифрами не нужен - очищаем динамическую память
	delete[] rand_numbers;
}

// Деструктор
Box::~Box()
{
	for (int i = 0; i < width; i++) delete cells[i];
	delete[] cells;
}

// Возможные ходы
vector <Cell*> Box::neighbours()
{
	vector<Cell*> moves;
	for (int i = -1; i < 2; i += 2)
	{
		int xi = null_cell->x + i;
		int yi = null_cell->y + i;
		if (xi < width && xi > -1) 
			moves.push_back(&cells[null_cell->y][xi]);
		if (yi < width && yi > -1)
			moves.push_back(&cells[yi][null_cell->x]);
	}
	return moves;
}

// Перемещение костяшки
void Box::moveTo(int x, int y)
{
	if (!(x >= width || y >= width || x < 0 || y < 0))
	{
		null_cell->number = cells[y][x].number;
		cells[y][x].number = 0;
		null_cell = &cells[y][x];
	}
}

// Ввод игррока
bool Box::playerInput(int key)
{
	int x = null_cell->x;
	int y = null_cell->y;
	switch (key)
	{
	case 77: // left
		moveTo(x - 1, y);
		break;
	case 72: // up
		moveTo(x, y + 1);
		break;
	case 75: // right
		moveTo(x + 1, y);
		break;
	case 80: // down
		moveTo(x, y - 1);
		break;
	default:
		return false;
	}
	return true;
}

// Проверка на решённость
bool Box::isSolved()
{
	int prev_iter = 0;
	for (int i = 0; i < width; ++i)
	{
		if (prev_iter != cells[i][0].number - 1)
			return false;
		for (int j = 1; j < width; ++j)
		{
			int verifiable = cells[i][j - 1].number;
			int to_verify = cells[i][j].number;
			if (verifiable == 0 || to_verify == 0)
				continue;
			prev_iter = cells[i][j].number;
			if ((verifiable != to_verify - 1))
				return false;
		}
	}
	return true;
}

// Оператор вывода
ostream& operator <<(ostream& out, const Box& box)
{
	out << endl;
	for (int i = 0; i < box.width; ++i)
	{
		out << '\t';
		for (int j = 0; j < box.width; ++j)
			out << box.cells[i][j] << '\t';
		out << endl;
	}
	return out;
}
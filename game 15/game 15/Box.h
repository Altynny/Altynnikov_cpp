#pragma once
#include "Cell.h"
#include <vector>

class Box {
	int width;			// ширина поля
	Cell** cells;		// массив клеток
	Cell* null_cell;	// указатель на пустую клетку
	bool isSolvable();  // проверка на решаемость
	vector<Cell*> neighbours(); // функция для поиска соседей
	void moveTo(int x, int y);  // функция для обмена числами нулевой и целевой клетки
public: 
	Box(int _side_size);
	~Box();
	bool playerInput(int key);	// ввод игрока
	bool isSolved();			// проверка на решённость
	friend ostream& operator <<(ostream& out, const Box& box);
};
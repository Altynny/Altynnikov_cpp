#pragma once
#include "Cell.h"
#include <vector>

class Box {
	int width;			// ������ ����
	Cell** cells;		// ������ ������
	Cell* null_cell;	// ��������� �� ������ ������
	bool isSolvable();  // �������� �� ����������
	vector<Cell*> neighbours(); // ������� ��� ������ �������
	void moveTo(int x, int y);  // ������� ��� ������ ������� ������� � ������� ������
public: 
	Box(int _side_size);
	~Box();
	bool playerInput(int key);	// ���� ������
	bool isSolved();			// �������� �� ����������
	friend ostream& operator <<(ostream& out, const Box& box);
};
#pragma once
#include <istream>
using namespace std;

class VectorException{};

const int DEFAULT_CAPACITY = 1;
class Vector {
	int* ptr;
	int v_size, v_capacity;
	void increaseCapacity(int newCapacity);
	void increaseSize(int newSize);
	void decreaseSize(int newSize);
public:
	explicit Vector(int startCapacity = DEFAULT_CAPACITY); // �����������
	~Vector();											   // ����������
	Vector(const Vector& vec);			   // �����������
	Vector& operator =(const Vector& vec); // ������������
	int& operator[](int index);            // ��������������

	void insert(int elem, int index);
	void insert(int elem);
	void remove(int index);
	
	int size() const;	  // ��������� ���-�� ���������
	void resize(int _size);   // ��������� �������
	int maxSize() const;      // ����������� ���������� ������ �������
	int capacity() const;  // ��������� ����������������� ������
	void reserve(int _size);  // �������������� ����� � ������
	void clear();			  // �������
	bool empty() const;		  // �������� �� �������
	void pop_back();		  // ������� ��������� �������
	void push_back(int elem); // �������� � �����

	friend ostream& operator <<(ostream& out, const Vector& arr);
};
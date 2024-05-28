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
	explicit Vector(int startCapacity = DEFAULT_CAPACITY); // конструктор
	~Vector();											   // деструктор
	Vector(const Vector& vec);			   // копирование
	Vector& operator =(const Vector& vec); // присваивание
	int& operator[](int index);            // индексирование

	void insert(int elem, int index);
	void insert(int elem);
	void remove(int index);
	
	int size() const;	  // получение кол-ва элементов
	void resize(int _size);   // изменение размера
	int maxSize() const;      // максимально допустимый размер массива
	int capacity() const;  // получение зарезервированной памяти
	void reserve(int _size);  // резервирование места в памяти
	void clear();			  // очистка
	bool empty() const;		  // проверка на пустоту
	void pop_back();		  // удалить последний элемент
	void push_back(int elem); // добавить в конец

	friend ostream& operator <<(ostream& out, const Vector& arr);
};
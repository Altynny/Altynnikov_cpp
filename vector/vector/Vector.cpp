#include "Vector.h"

void Vector::increaseCapacity(int newCapacity) {
	v_capacity = newCapacity < v_capacity * 2 ? v_capacity * 2 : newCapacity;
	int* newPtr = new int[v_capacity];
	for (int i=0; i<v_size; i++)
		newPtr[i]=ptr[i];
	delete[] ptr;
	ptr = newPtr;
}

void Vector::increaseSize(int newSize) {
	if (newSize > v_capacity) increaseCapacity(newSize);
	v_size = newSize;
	for (int i = v_size - 1; i > 0; i--) {
		if (ptr[i] > 0) break;
		ptr[i] = 0;
	}
}

void Vector::decreaseSize(int newSize) {
	for (int i = v_size - newSize; i > 0; i--)
		this->pop_back();
}

Vector::Vector(int startCapacity) {
	if (startCapacity <= 0)
		v_capacity = DEFAULT_CAPACITY;
	else
		v_capacity = startCapacity;
	ptr = new int[v_capacity];
	v_size = 0;
}

Vector::~Vector()
{
	delete[] ptr;
}

Vector::Vector(const Vector& vec) {
	ptr = new int[vec.v_capacity];
	v_size = vec.v_size;
	v_capacity = vec.v_capacity;
	for (int i = 0; i < v_size; i++)
		ptr[i] = vec.ptr[i];
}

Vector& Vector::operator=(const Vector& vec) {
	if (this == &vec)
		return *this;
	if (v_capacity != vec.v_capacity)
	{
		delete[] ptr;
		ptr = new int[vec.v_capacity];
		v_capacity = vec.v_capacity;
	}
	v_size = vec.v_size;
	for (int i = 0; i < v_size; i++)
		ptr[i] = vec.ptr[i];
	return *this;
}

int& Vector::operator [](int index)
{
	if (index >= v_size || index < 0)
		throw VectorException();
	else
		return ptr[index];
}

void Vector::insert(int elem, int index)
{
	if (index < 0 || index > v_size)
		throw VectorException();
	if (v_size == v_capacity)
		// Закрытая функция, увеличивающая предельный размер
		increaseCapacity(v_size + 1);
	// Если index==size, этот цикл не выполнится ни разу
	for (int j = v_size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];
	v_size++;
	ptr[index] = elem;
}

void Vector::insert(int elem)
{
	insert(elem, v_size);
}

void Vector::remove(int index)
{
	if (index < 0 || index >= v_size)
		throw VectorException();
	for (int j = index; j < v_size - 1; j++)
		ptr[j] = ptr[j + 1];
	ptr[v_size - 1] = 0;
	v_size--;
}


int Vector::size() const {
	return v_size;
}

void Vector::resize(int _size) {
	if (v_size < 0)
		throw VectorException();
	if (_size > v_size)
		increaseSize(_size);
	else if (_size < v_size)
		decreaseSize(_size);
}

int Vector::capacity() const {
	return v_capacity;
}

void Vector::reserve(int _size) {
	if (_size > v_capacity)
		increaseCapacity(_size);
}

bool Vector::empty() const {
	return v_size < 0 ? true : false;
}

void Vector::clear() {
	delete[] ptr;
	ptr = new int[v_capacity];
	v_size = 0;
}

void Vector::pop_back() {
	ptr[v_size - 1] = 0;
	v_size--;
}

void Vector::push_back(int elem) {
	if (v_size == v_capacity)
		increaseCapacity(v_size + 1);
	ptr[v_size++] = elem;
}

ostream& operator <<(ostream& out, const Vector& vec)
{
	out << "Total size: " << vec.v_size << endl;
	for (int i = 0; i < vec.v_size; i++)
		out << vec.ptr[i] << endl;
	return out;
}
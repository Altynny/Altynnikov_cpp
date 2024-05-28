#pragma once
#include <ostream>

// __Класс элемента линейного списка__

template <class T> class LineListItem
{
	T data;
	LineListItem* next;
public:
	LineListItem(const T& _data, LineListItem* _next);
	const T& getData() const;
	LineListItem* getNext();
	template <class T> friend class LineList;
};


// __Класс линейного списка__

class LineListException{}; // класс исключений линейного списка
template <class T> class LineList
{
	LineListItem<T>* start;
	LineList(const LineList& list);
public:
	LineList();
	~LineList();
	LineListItem<T>* getStart();
	//LineListItem<T>& operator[](int index);
	void deleteFirst();
	void deleteAfter(LineListItem<T>* ptr);
	void insertFirst(const T& data);
	void insertAfter(LineListItem<T>* ptr, const T& data);
	LineList& operator =(const LineList& list);
	template <class T> friend std::ostream& operator <<(std::ostream& out, LineList& list);
};



// __Определения методов элемента__

template <class T> LineListItem<T>::LineListItem(const T& _data, LineListItem<T>* _next)
{
	data = _data;
	next = _next;
}

template <class T> const T& LineListItem<T>::getData() const
{
	return data;
}

template <class T> LineListItem<T>* LineListItem<T>::getNext()
{
	return next;
}



// __Определения методов списка__

// ____Конструкторы____

// ______По умолчанию______
template <class T> LineList<T>::LineList()
{
	start = 0;
}

// ______Деструктор______
template <class T> LineList<T>::~LineList()
{
	while (start)
		deleteFirst();
}


// ____Взаимодействие с элементами____

// ______Получение ссылки на начало______
template <class T> LineListItem<T>* LineList<T>::getStart()
{
	return start;
}

// ______Удаление первого элемента______
template <class T> void LineList<T>::deleteFirst()
{
	if (start)
	{
		LineListItem<T>* temp = start->next;
		delete start;
		start = temp;
	}
	else throw LineListException();
}

// ______Удаление после заданного элемента______
template <class T> void LineList<T>::deleteAfter(LineListItem<T>* ptr)
{
	if (ptr && ptr->next) {
		LineListItem<T>* temp = ptr->next;
		ptr->next = ptr->next->getNext;
		delete temp;
	}
	else throw LineListException();
}

// ______Вставка в начало списка______
template <class T> void LineList<T>::insertFirst(const T& data)
{
	LineListItem<T>* second = start;
	start = new LineListItem<T>(data, second);
}

// ______Вставка после заданного элемента______
template <class T> void LineList<T>::insertAfter(LineListItem<T>* ptr, const T& data)
{
	if (ptr) {
		LineListItem<T>* temp = ptr->next;
		ptr->next = new LineListItem<T>(data, temp);
	}
}

// ____Операторы____

template <class T> LineList<T>& LineList<T>::operator=(const LineList& list)
{
	// Удаляем данные списка назначения и создаём сначала
	this->~LineList();
	start = 0;

	// Получаем начало списка для копирования и вставляем в начало списка назначения
	LineListItem<T>* list_first = list.getStart();
	this->insertFirst(list_first);

	// Получаем начало списка назначения для последующей вставки
	LineListItem<T>* item = this->getStart();
	for (LineListItem<int>* it = list_first->getNext(); it; it = it->getNext())
	{
		this->insertAfter(item, it->getData());
		item = item->getNext();
	}
}

// ______Вывод______
template <class T> std::ostream& operator <<(std::ostream& out, LineList<T>& list)
{
	LineListItem<T>* ptr = list.getStart();
	if (!ptr)
		out << "EMPTY";
	else while (ptr)
	{
		out << ptr->getData() << ' ';
		ptr = ptr->getNext();
	}
	return out;
}
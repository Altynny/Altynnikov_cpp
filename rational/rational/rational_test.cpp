﻿// rational.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include "Rational.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Rational a(1, 2), b(1, -6);
    cout << "a=" << a << " b=" << b << " a+b=" << a+b << endl;
    cout << "a(" << a << ") *= b(" << b << ")" << endl;
    a *= b;
    cout << "a=" << a << " b=" << b << " a-b=" << a - b << endl;
    Rational c = 3;
    cout << "b=" << b << " c=" << c << " b/c=" << b / c << endl;

    Rational e(7, 8), f(5, 12);
    cout << "e=" << e << " f=" << f << " e+f=?" << endl;
    cout << "Введите результат g=m/n в формате: m n" << endl;
    Rational g;
    cin >> g;
    if (e + f != g)
        cout << "Неправильно! e+f=" << e + f << endl;
    else
        cout << "Правильно!" << endl;

    return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

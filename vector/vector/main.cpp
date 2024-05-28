// vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "locale"
#include "Vector.h"

void iteration(Vector* v, int start_position, int step);

int main()
{
    setlocale(LC_ALL, "Russian");
    int N, k;
    cout << "Введите кол-во элементов N и шаг k: ";
    cin >> N >> k;
    k--;
    Vector v(N);

    for (int i = 1; i < N+1; i++) v.push_back(i);
    iteration(&v, k, k);
    //v.remove(k-(v.size()-7));
    /*int remain = 0;
    while (v.size() > 1 && remain != -1)
    {
        for (int i = k - remain; i < v.size();)
        {
            cout << "remain - " << remain << "\ni - " << i << endl << v;
            if (k+1 > v.size()) 
            {
                remain = -1;
                break;
            }
            else 
            {
                remain = 0;
                v.remove(i);
                i += k;
                if (i > v.size())
                {
                    remain = i-v.size();
                    break;
                }
            }
        }
    }*/
    cout << v[k];
}

void iteration(Vector* v, int start_position, int step) 
{
    if (v->size() == step+1) return;
    for (int i = start_position; ; i += step)
        if (i < (v->size()))
            v->remove(i);
        else
        {
            cout << i << ' ' << v->size()<< endl << *v << endl;
            iteration(v, step-(i-v->size()), step);
            break;
        }    
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

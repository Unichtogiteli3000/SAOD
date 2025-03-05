

#include <iostream>
using namespace std;

/*void Swap(int* pa, int* pb) {
    int c = *pb;
    *pb = *pa;
    *pa = c;
}*/

void Swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int main()
{/*
    int x = 3;
    int* p = &x; // &x - адрес переменной x в памяти, p - указатель, который хрнаит адрес x
    cout << x << ' ' << *p << ' ' << p << endl; // * - переходим по адресу в памяти для получения значения
    p++;
    cout << p << endl;
    cout << p - &x << endl;

    typedef unsigned char byte; // Переименовываем uc в byte

    byte *pb = (byte *)--p; // вернули указатель на x и преобразовали
    for (byte *pt = pb; pt - pb < sizeof(int); pt++) // Цикл выполняется, пока разница между pt и pb меньше размера int (обычно 4 байта).
        cout << (int)*pt << ' '; // выводим как int
    cout << endl;*/

    int a = 3, b = 5;
    cout << a << ' ' << b << endl;
    /*int c = b;
    b = a;
    a = c;*/
    Swap(a, b);
    cout << a << ' ' << b << endl;
}

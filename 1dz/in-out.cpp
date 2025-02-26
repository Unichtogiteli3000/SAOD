// in-out.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()
{
	int x, y;

	cout << "x = ? "; cin >> x; // Подсказка и ввод x
	cout << "y = ? "; cin >> y; // Подсказка и ввод y
	cout << x << " + " << y << " = " << x + y << endl;
	cout << x << " - " << y << " = " << x - y << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " / " << y << " = " << x / y << endl;
	cout << x << " ^ " << y << " = " << pow(x, y) << endl;
}

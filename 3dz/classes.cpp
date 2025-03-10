#include "Complex.h"
#include <iostream>

int main()
{
    Complex c = 3;
    Complex a(1, 2);
    std::cout << a << std::endl;

    std::cout << "Sum: " << a + a << ", Subtraction: " << a - a << std::endl;
    std::cout << "Multiplication: " << a * a << ", Division: " << a / a << std::endl;

    Complex arr[4];
    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " " << std::endl;
    }
    std::cout <<" " << std::endl;
    Complex v[4]{1, 2, Complex(2,3)};
    for (int i = 0; i < 4; i++) {
        std::cout << v[i] << " " << std::endl;
    }
    std::cout << " " << std::endl;
    Complex* pc;
    pc = new Complex(1, 2);
    std::cout << *pc << std::endl;
    pc = new Complex;
    std::cout << *pc << std::endl;
    pc = new Complex(1);
    std::cout << *pc << std::endl;
    std::cout << "Re: " << pc -> Re << ", Im: " << pc -> Im << std::endl;
    delete pc;
    Complex* array = new Complex[3]; // при использовании оператора new возвращается указатель на начало выделенного блока паияти из динамической памяти (heap), поэтому без указателя не работает.
    array[0] = Complex(1, 2);
    array[2] = Complex(2, 8);
    delete[] array;
}



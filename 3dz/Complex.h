#pragma once // ������������� ��������� ��������� ������������ �����
#include <iostream>
#include <cmath>

class Complex
{
public:
	double Re, Im;

	Complex(double re = 0, double im = 0) : Re(re), Im(im) {}
	
	Complex operator+(const Complex& c) const /*�� �������� ��������� �������, � �������� �� ���������� */ {
		return Complex(Re + c.Re, Im + c.Im);
	}
	Complex operator-(const Complex& c) const {
		return Complex(Re - c.Re, Im - c.Im);
	}
	Complex operator*(const Complex& c) const {
		return Complex(Re * c.Re - Im * c.Im, Re * c.Im + c.Re * Im);
	}
	Complex operator/(const Complex& c) const {
		double dopArgument = pow(c.Re, 2) + pow(c.Im, 2);
		return Complex((Re * c.Re + Im * c.Im) / dopArgument, (-Re * c.Im + c.Re * Im) / dopArgument);
	}

	Complex Conjugate() const {
		return Complex(Re, -Im);
	}
	double Mod() const {
		return sqrt(pow(Re, 2) + pow(Im, 2));
	}
	double Arg() const {
		if (Mod() == 0) {
			return 0;
		}
		else if (Re > 0) {
			return atan(Im / Re);
		}
		else if (Re < 0 && Im >= 0) {
			return acos(-1) + atan(Im / Re);
		}
		else if (Re < 0 && Im < 0) {
			return -acos(-1) - atan(Im / Re);
		}
		else if (Im > 0) {
			return acos(0);
		}
		else { // ���� ������� ������� < 0, �� ���� Im = 0, �� ������ �� �������
			return -acos(0);
		}
	}
};

inline std::ostream& operator<<(std::ostream& o, const Complex& c) { // �������� << ���������� ������ �� ����� (std::ostream), ����� ������������ ������� ����������. ��������: std::cout << c1 << " " << c2; ���� �� �������� �� ��������� ������, ����� ������� ���� �� ����������.
	return o << '(' << c.Re << ", " << c.Im << ')';
} // �������� c ��������� ��� ����������� ������ (const Complex&), ������ ��� ��� �����������, ��� ������� c �� ����� ������ ������ �������; �������������� ��������� ����������� �������, ��� �������� ����� ��� ������� ��������.


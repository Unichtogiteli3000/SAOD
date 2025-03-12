#pragma once
#include <iostream>
#include <cstring>

class Str {
	char* m_pszText;
public:
	Str() 	//����������� ��� ���������� (default)*
	{
		m_pszText = new char[1] {0};
	}
	Str(const char* p)
	{
		if (p) {
			m_pszText = new char[strlen(p) + 1];
			strcpy_s(m_pszText, strlen(p) + 1, p);
		}
		else
			m_pszText = new char[1] {0};
	}
	Str(const Str& s) //����������� ������ �� ������
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	

	const Str& operator=(const Str& s) //����������� ������ �� ������
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //����������� ������� ������//������ ������ �����������
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}



	~Str() { delete[] m_pszText; }

	operator const char* ()const { return m_pszText; }

	friend std::ostream& operator<<(std::ostream& os, const Str& s) { // �������� << ���������� ������ �� ����� (std::ostream), ����� ������������ ������� ����������. ��������: std::cout << c1 << " " << c2; ���� �� �������� �� ��������� ������, ����� ������� ���� �� ����������.
		os << s.m_pszText; // ������� C-������
		return os; /*� inline �� ��������*/
	}

	Str& operator+=(const char* sz) {
		if (!sz) return *this;
		int currentLength = strlen(m_pszText);
		int appendLength = strlen(sz);

		//������ ��������� ����� ��� ����������� ������
		int newLen = currentLength + appendLength;
		char* newText = new char[currentLength + appendLength + 1];

		strcpy_s(newText, newLen + 1, m_pszText); // ����������� � �����
		strcat_s(newText, newLen + 1, sz); //��� � �����
		delete[] m_pszText; //������� ������
		m_pszText = newText;/*��������� ���������*/

		return *this; /*��������� ���� ����� ������������ ������� ����������*/
	}
	Str operator+(const char* sz) const {
		Str result(*this); //�������� ����� �������� �������
		result += sz;
		return result;
	}
};

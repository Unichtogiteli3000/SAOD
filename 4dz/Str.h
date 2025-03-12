#pragma once
#include <iostream>
#include <cstring>

class Str {
	char* m_pszText;
public:
	Str() 	//Конструктор “по умолчанию” (default)*
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
	Str(const Str& s) //Константная ссылка на объект
	{
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
	}

	

	const Str& operator=(const Str& s) //Константная ссылка на объект
	{
		if (&s == this) return *this;
		delete[] m_pszText;	 //Освобождаем текущие данные//Дальше просто копирование
		m_pszText = new char[strlen(s.m_pszText) + 1];
		strcpy_s(m_pszText,
			strlen(s.m_pszText) + 1,
			s.m_pszText);
		return *this;
	}



	~Str() { delete[] m_pszText; }

	operator const char* ()const { return m_pszText; }

	friend std::ostream& operator<<(std::ostream& os, const Str& s) { // оператор << возвращает ссылку на поток (std::ostream), чтобы поддерживать цепочку операторов. Например: std::cout << c1 << " " << c2; Если бы оператор не возвращал ссылку, такая цепочка была бы невозможна.
		os << s.m_pszText; // Выводим C-строку
		return os; /*с inline не работает*/
	}

	Str& operator+=(const char* sz) {
		if (!sz) return *this;
		int currentLength = strlen(m_pszText);
		int appendLength = strlen(sz);

		//Создаём временный буфер для объединённой строки
		int newLen = currentLength + appendLength;
		char* newText = new char[currentLength + appendLength + 1];

		strcpy_s(newText, newLen + 1, m_pszText); // копирование в буфер
		strcat_s(newText, newLen + 1, sz); //доб в конец
		delete[] m_pszText; //очистка памяти
		m_pszText = newText;/*обновлние указателя*/

		return *this; /*благодаря тому можно использовать цепочку операторов*/
	}
	Str operator+(const char* sz) const {
		Str result(*this); //Создание копии текущего объекта
		result += sz;
		return result;
	}
};

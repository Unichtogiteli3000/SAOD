#pragma once
#include "_str.h"

class Str
{
	_str* m_pStr;
public:
	// конструкторы
	Str() {
		m_pStr = new _str;
	}
	Str(const char* p) { m_pStr = new _str(p); }
	Str(const Str& s) {
		m_pStr = s.m_pStr;
		m_pStr->AddRef();
	}

	~Str() {
		m_pStr->Release();
	}

	Str& operator=(const Str& s) {
		if (this != &s) {
			s.m_pStr->AddRef();
			m_pStr->Release();
			m_pStr = s.m_pStr;
		}
		return *this;
	}

	int len() const {
		return strlen(m_pStr->m_pszData);
	}

	Str& operator+=(const Str& s) {
		char* newData = new char[len() + s.len() + 1];
		strcpy_s(newData, len() + 1, m_pStr->m_pszData);
		strcat_s(newData, len() + s.len() + 1, s.m_pStr->m_pszData);
		m_pStr->Release();
		m_pStr = new _str(newData);
		delete[] newData;
		return *this;
	}

	operator const char* () const {
		return m_pStr->m_pszData;
	}

	int rfind(const char* t, int off) const;
};



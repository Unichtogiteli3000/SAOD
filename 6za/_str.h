#pragma once
#include <string.h>

class Str;

class _str {
    char* m_pszData;// ”казатель на строку
    int m_nCount;// —чЄтчик ссылок
    friend class Str;//теперб класс Str стал дружественным, а следовательно может использовать все приватные методы _str

    //все методы приватные
    _str() {
        m_pszData = new char[1] {0};
        m_nCount = 1;
    }

    _str(const char* p) {
        m_nCount = 1;
        m_pszData = new char[strlen(p) + 1];
        strcpy_s(m_pszData, strlen(p) + 1, p);
    }

    ~_str() {
        delete[] m_pszData;// осовбождение пам€ти
    }

    void AddRef() { m_nCount++; }
    void Release() {
        if (--m_nCount == 0) delete this;// =m_nCount--; if(m_nCount==0) при отсутствии ссылок удал€етс€
    }
};


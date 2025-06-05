#pragma once
#include "PF.h"
class KMP_StateMachine {
private:
    PF pf;
    int state;
    char* pattern;
    int patternSize;

public:
    KMP_StateMachine(const char* s, int sz) {
        pattern = new char[sz];
        memcpy(pattern, s, sz); // копируем шаблон
        patternSize = sz;

        pf.Init(s, sz);
        state = 0;
    }

    ~KMP_StateMachine() {
        delete[] pattern;
    }

    void Accept(char ch) {
        while (state > 0 && ch != pattern[state]) {
            state = pf[state - 1];
        }
        if (ch == pattern[state]) {
            ++state;
        }
    }

    bool IsFinal() {
        return state == static_cast<int>(pf);
    }
};
#include "Str.h"

int Str::rfind(const char* t, int off) const {
    int t_len = 0;
    while (t[t_len] != '\0') t_len++;
    int s_len = 0;
    while (m_pStr->m_pszData[s_len] != '\0') s_len++;

    if (t_len == 0) return -1;
    if (off >= s_len) off = s_len - 1;

    for (int i = off; i >= 0; i--) {
        //помещается ли строка начиная с i
        if (i + t_len > s_len) continue;
        bool found = true;
        for (int j = 0; j < t_len; j++) {
            if (m_pStr->m_pszData[i + j] != t[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}
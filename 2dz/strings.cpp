
#include <iostream>
using namespace std;

int len(const char* s) {
    int k = 0;
    while (*s != '\0') {
        s++;
        k++;
    }
    return k;
}

int compare(const char* s, const char* t) {
    if (len(s) > len(t)) {
        return 1;
    }
    else if (len(s) < len(t)) {
        return -1;
    }
    else {
        return 0;
    }
}

int main()
{
    char str[] = "Hello!";
    //cout << str << endl;
    //cout << strlen(str) << ' ' << sizeof(str) << endl; // sizeof подсчитывает значение, включаю завершающий нулевой символ '\0'

    //char t[32];

    //for (char* pd = t, *ps = str; *pd++ = *ps++;);
    //cout << t  << ' ' << strlen(t) << ' ' << sizeof(t) << endl;
    char v[32];
    /*for (int i = 0; i < strlen(str); i++) {
        cout << str[i] << endl;
        v[i] = str[i];
    }*/
    char* pd = v, * ps = str;
    for (int i = 0; i < strlen(str); i++, ps++, pd++) {
        *pd = *ps;
    }
    v[strlen(str)] = '\0';
    cout << v << endl;

    cout << len(str) << endl;
}

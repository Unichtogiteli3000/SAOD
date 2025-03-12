#include <iostream>
#include <cstring>
#include "Str.h"
using namespace std;

void Test(Str s) {

}

int main()
{
    Str s = "123";

    cout << "s: " << s << endl;

    cout << "lEN STR: " << strlen(s) << endl;

    int length = strlen(s);

    cout << "2. lEN STR: " << length << endl;

    Test(s);

    cout << "s: " << s << endl;

    cout << "lEN STR: " << strlen(s) << endl;
    
    {
        Str t;
        t = s;
    }

    cout << "s: " << s << endl;

    cout << "lEN STR: " << strlen(s) << endl;

    Str s1 = "hello,";
    Str s2 = "world";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1 += s2;
    cout << "s1 after adding s2: " << s1 << endl;
    s1 += " How are you?"; /*добавление C- Строки*/
    cout << "s1 after addinf C-строки: " << s1 << endl;

    Str s4 = s1 + "How are you?";
    cout << "s4 : " << s4 << endl;

    return 0;
}

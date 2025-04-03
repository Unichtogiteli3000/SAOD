#include <iostream>
#include "Str.h"
using namespace std;

int main()
{
	Str s = "Hello, world! Hello again!";
	
	cout << "empty underString" << endl;
	cout << s.rfind("", 5) << endl;

	cout << "inputs Hello" << endl;
	cout << s.rfind("Hello", 20) << endl;

	cout << "off za predelami" << endl;
	cout << s.rfind("world", 5) << endl;

	cout << "sovapdenie with beginning" << endl;
	cout << s.rfind("Hello", 0) << endl;

	return 0;
}

#include "Test.h"
#include <iostream>
using namespace std;

//Test globalTest;

void foo(Test t) {
    cout << "foo is running!!!!!!!" << endl;
}
int main()
{
   /*cout << "BEGIN OF MAIN" << endl;
    cout << "1.de beggining of work" << endl; 
    {
        cout << "now we will create an obj" << endl;
        Test testObj;
        int n;
        cout << "Input amount of balls" << endl;
        cin >> n;
        cout << "Amount: " << n << endl;
        Test obj1;
        Test obj2;
    }
    cout << "obj will die now" << endl;
    cout << "END OF MAIN" << endl;
    return 0;*/

    /*cout << "begin og prog" << endl;

    cout << "make dinamic onj" << endl;
    Test* p = new Test;

    cout << "work with d obj" << endl;
    cout << "4mount of obj-s: " << Test::nCount << endl;
    cout << "delete de dinamic obj" << endl;
    delete p;
    cout << "4mount of obj-s: " << Test::nCount << endl;
    cout << "end of prog" << endl; // Деструктор НЕ вызывается автоматически для динамических объектов


    return 0;*/

    /*cout << "MAKE AN ARRAY" << endl;
    Test* arr = new Test[3];
    cout << "delete an array" << endl;
    delete[] arr;

    return 0;*/
    /*
    cout << "create an original obj" << endl;
    Test orig;
    
    cout << "call a foo function" << endl;
    foo(orig);

    cout << "End of main" << endl;
    return 0;*/
    
    /*cout << "Now we make child obj" << endl;
    Child chObj;

    cout << "End of prog" << endl;
    return 0;*/

    /*cout << "begin of main" << endl;

    {
        cout << "we make aggregate obj" << endl;
        Aggregate agObj;
    }

    cout << "End of main" << endl;
    return 0;*/

    cout << "Test for Aggregate<Test>" << endl;
    {
        AggregateT<Test> aggTest;
    }

    cout << "Test for Aggregate<Child>" << endl;
    {
        AggregateT<Child> aggChild;
    }

    return 0;
 }
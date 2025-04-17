#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    int Val;

    Test() {
        Val = 0;
        cout << "Test sconstruirovan" << endl;
    }

    ~Test() {
        cout << "Test razrushen" << endl;
    }
};

int main() {
    {
        //с массивом
        shared_ptr<Test[]> sp(new Test[3]);
        sp.get()[0].Val = 1;
        sp.get()[1].Val = 2;
        sp.get()[2].Val = 3;

        for (int i = 0; i < 3; ++i)
            cout << "sp[" << i << "].Val = " << sp.get()[i].Val << endl;
    }

    cout << "........." << endl;

    {
        //с custom deleter
        shared_ptr<Test> sp(new Test[3], default_delete<Test[]>());
        Test* raw = sp.get();
        raw[0].Val = 10;
        raw[1].Val = 20;
        raw[2].Val = 30;

        for (int i = 0; i < 3; ++i)
            cout << "sp[" << i << "].Val = " << raw[i].Val << endl;
    }

    cout << "........." << endl;

    {
        //unique_ptr
        unique_ptr<Test[]> p(new Test[3]);
        p[0].Val = 100;
        p[1].Val = 200;
        p[2].Val = 300;

        for (int i = 0; i < 3; ++i)
            cout << "p[" << i << "].Val = " << p[i].Val << endl;

        cout << "........." << endl;

        p.reset(new Test[2]);
        cout << "........." << endl;
    }

    return 0;
}

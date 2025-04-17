#include <iostream>
#include <list>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int M = 200;

    cout << "N\tTime (microseconds)" << endl;

    for (int N = 200; N <= 1000; N += 200) {
        list<int> lst;
        for (int i = 0; i < N; ++i)
            lst.push_back(i);

        int k = 0;
        auto start = steady_clock::now();
        for (int i = 0; i < M; ++i) {
            lst.push_front(i);
            ++k;
            lst.pop_front();
            ++k;
        }
        auto stop = steady_clock::now();
        auto dt = duration_cast<microseconds>(stop - start).count();
        cout << N << "\t" << dt << endl;
    }

    return 0;
}

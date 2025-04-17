#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int M = 200;

    cout << "N\tTime (microseconds)" << endl;

    for (int N = 200; N <= 1000; N += 200) {
        vector<int> v;
        for (int i = 0; i < N; ++i)
            v.push_back(i);

        int k = 0;
        auto start = steady_clock::now();
        for (int i = 0; i < M; ++i) {
            v.insert(v.begin(), i);
            ++k;
            v.erase(v.begin());
            ++k;
        }
        auto stop = steady_clock::now();
        auto dt = duration_cast<microseconds>(stop - start).count();
        cout << N << "\t" << dt << endl;
    }

    return 0;
}

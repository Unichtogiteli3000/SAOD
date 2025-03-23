#include <iostream>
#include <cmath>
using namespace std;

class PrimeDivisors {
private:
    int value;
    int* index;

    bool isPrime(int n) const { // норм
        if (n <= 1) {
            return false;
        }
        else if (n == 2 || n == 3) {
            return true;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int nextPrime(int n) const {
        while (isPrime(++n));
        return n;
    }

    int kolDelForNatur(int n) const { // норм
        if (n == 1 || n == 2) {
            return n;
        }
        int kol = 2;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                kol++;
            }
        }
        return kol;
    }

    bool isDivisor(int n) const { // норм
        int kolDel = kolDelForNatur(n);
        if (n >= 1 && kolDel != 2 && isPrime(kolDel)) {
            return true;
        }
        return false;
    }

    int primeDivisor(int ind) const { // Норм
        int thatInd = 0, number = 4;
        while (thatInd != ind) {
            number++;
            if (isPrime(kolDelForNatur(number)) && isDivisor(number)) {
                thatInd++;
            }
        }
        *index = ind;
        return number;
    }

    int indexOfD(int num) {
        int ind = 0;
        if (num == 4) {
            return ind;
        }
        for (int i = 9; i <= num; i++) {
            if (isDivisor(i)) {
                ind++;
            }
        }
        return ind;
    }
public:
    PrimeDivisors() : value(4), index(new int(0)) {}
    explicit PrimeDivisors(unsigned int ind) : index(new int(ind)) {
        value = primeDivisor(ind);
    }
    PrimeDivisors(int num) : index(new int(-1)) {
        if (isDivisor(num)) {
            value = num;
            *index = indexOfD(num);
        }
        else {
            value = -1;
        }
    }
    PrimeDivisors(const PrimeDivisors& other) : value(other.value), index(new int(*other.index)) {}



    ~PrimeDivisors() {
        delete index;
    }

    int get_index() const {
        return *index;
    }

    PrimeDivisors& operator=(const PrimeDivisors& other) {
        if (this != &other) {
            value = other.value;
            delete index;
            index = new int(*other.index);
        }
        return *this;
    }


    operator int() const {
        return value;
    }

    friend ostream& operator<<(ostream& os, const PrimeDivisors number) {
        if (number.value == -1) {
            os << "";
        }
        else {
            os << number.value;
        }
        return os;
    }
    
    PrimeDivisors& operator++() { /*до этого мы просто увеличивали value на 1, увеличиваем value, а следовательно и i до следующего числа*/
        value = primeDivisor(++*index);
        //(*index)++;
        return *this;
    }

    PrimeDivisors operator++(int) {
        PrimeDivisors temp = *this;
        ++(*this);
        return temp;
    }

    friend size_t& operator+=(size_t& siz, const PrimeDivisors prD) {
        siz += prD.value;
        return siz;
    }
};

int main()
{
    PrimeDivisors pd(15u);
    cout << pd.get_index() << " " << int(pd) << endl;

    for (PrimeDivisors i = 0; i < 2000; ++i) {
        cout << i << " ";
    }
    cout << endl;

    size_t sum = 0;
    for (PrimeDivisors i = 0; i.get_index() < 30; sum += i, i++);
    cout << sum << endl;
}
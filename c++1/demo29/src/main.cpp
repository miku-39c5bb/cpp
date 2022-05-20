#include <iostream>

using namespace std;

int main() {
    int i = 1024, j = 2;
    cout << i + j << endl;
    cout << i - j << endl;
    cout << i * j << endl;
    cout << i / j << endl;
    cout << i % j << endl;

    long a;
    double d;
    float f;

    cout << 5 + 10 * 20 / 2 << endl;

    int k = -i;
    cout << k << ", " << i << endl;

    int m = --i;
    cout << m << ", " << i << endl;

    short sv = 32767;
    short ival = 1;
    sv += ival;
    cout << "溢出 sv = " << sv << endl;

    // double dval = 10 / 3;
    double dval = 10.0 / 3.0;
    cout << dval << endl;

    int ival2 = 42;
    cout << ival2 % 12 << endl;

    cout << -21 / -8 << endl;
    cout << -21 % -8 << endl;
    cout << -21 / 8 << endl;
    cout << -21 % 8 << endl;
    cout << 21 / -8 << endl;
    cout << 21 % -8 << endl;

    for (size_t i = 1; i <= 100; i++) {
        cout << i << " ";
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    return 0;
}
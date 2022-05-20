#include <iostream>

using namespace std;

int add(int x, int y) { return x + y; }
int add2(const int x, const int y) { return x + y; }

// void addOne(const int x) { x = x + 1; }

int main()
{
    int a, b;
    const int m = 8, n = 9;
    a = 1;
    b = 2;

    // int k = add(a, b);
    int k = add2(a, b);
    cout << k << endl;

    // k = add(m, n);
    k = add2(m, n);
    cout << k << endl;

    return 0;
}
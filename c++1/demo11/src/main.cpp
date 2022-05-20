#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<32> a;
    cout << a << endl;

    a[5] = 1;
    cout << a << endl;

    for (int index = 0; index != a.size(); index += 2) {
        // a[index] = 1;
        a.set(index);
    }
    cout << a << endl;

    a.set();
    cout << a << endl;

    a.reset(5);
    cout << a << endl;

    a.flip();
    cout << a << endl;

    a.flip(8);
    cout << a << endl;

    a.reset();
    cout << a << endl;

    a.set(8);
    cout << a << endl;

    a.flip();
    cout << a << endl;

    unsigned long long b = a.to_ulong();
    cout << b << endl;

    string c(a.to_string());
    cout << c << endl;

    return 0;
}
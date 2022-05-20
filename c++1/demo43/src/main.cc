#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a;
    cout << sizeof(int) << endl;
    cout << sizeof a << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(bool) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(wchar_t) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(long double) << endl;

    int x[] = {2, 4, 6, 8, 10};
    for (int k = 0, cnt = 10; k < sizeof(x) / sizeof(int); ++k, --cnt) {
        x[k] = cnt;
    }

    print_array(x, sizeof(x) / sizeof(x[0]));

    double dval = 1.23;
    double* p = &dval;
    cout << *p << endl;
    cout << sizeof(p) << endl;   // 指针的大小
    cout << sizeof(*p) << endl;  // 指针指向对象的大小

    return 0;
}
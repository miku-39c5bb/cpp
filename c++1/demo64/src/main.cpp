#include <cstdlib>
#include <iostream>

using namespace std;

void do_a() {
    cout << "a" << endl;
    cout << "aa" << endl;
    return;
    cout << "aaa" << endl;
    cout << "aaaa" << endl;
}

void swap(int& v1, int& v2) {
    if (v1 == v2) {
        return;
    }
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
}

int main() {
    do_a();
    int a = 1, b = 10;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    return EXIT_SUCCESS;  // 0
    return EXIT_FAILURE;  // 1
    // return 0;  // 返回0表示没有出错
}
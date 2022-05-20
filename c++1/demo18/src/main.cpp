#include <iostream>

using namespace std;

int main() {
    int ival = 1024, ival2 = 2048;
    int *pi = &ival, *pi2 = &ival2;
    int &ri = ival, &ri2 = ival2;

    int** ppi = &pi;
    cout << **ppi << endl;
    pi = pi2;
    pi2 = *ppi;
    cout << **ppi << endl;

    cout << ival << ", " << *pi << ", " << ri << endl;
    cout << ival2 << ", " << *pi2 << ", " << ri2 << endl;
    // pi = pi2;  // 修改了指针指向的对象，指向另一个对象
    // pi2 = pi;
    ri = ri2;  // 没有修改引用指向的对象，修改了引用指向对象的值(赋值)
    cout << ival << ", " << *pi << ", " << ri << endl;
    cout << ival2 << ", " << *pi2 << ", " << ri2 << endl;

    return 0;
}
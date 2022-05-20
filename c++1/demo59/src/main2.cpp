#include <iostream>

using namespace std;

// v1、v2 是 int* 的引用
void ptrswap(int*& v1, int*& v2) {
    int* temp = v1;
    v1 = v2;
    v2 = temp;
}

int main() {
    int i = 10, j = 20;
    // ptrswap(&i, &j); // 不能这么做
    int* pi = &i;
    int* pj = &j;
    cout << i << " " << j << endl;
    cout << *pi << " " << *pj << endl;
    ptrswap(pi, pj);
    cout << i << " " << j << endl;
    cout << *pi << " " << *pj << endl;

    return 0;
}
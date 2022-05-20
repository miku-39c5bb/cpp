#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int a[10];  // 静态数组，堆栈上创建

    int n;
    cout << "你想要多大的数组：" << endl;
    cin >> n;

    int* p = (int*)malloc(n * sizeof(int));  // 动态数组，在堆上创建
    if (p != NULL) {
        cout << "malloc创建动态数组成功！" << endl;
    }

    int* pia = new int[n];  // 动态数组，在堆上创建
    if (pia != NULL) {
        cout << "new创建动态数组成功！" << endl;
    }

    free(p);
    delete[] pia;

    return 0;
}
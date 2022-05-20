#include <iostream>

using namespace std;

void f() {
    cout << "f()" << endl;
}

void f(int a) {
    cout << "f(int a)" << endl;
}

void f(int a, int b) {
    cout << "f(int a,int b)" << endl;
}

void f(miku a, miku b = 3.14) {
    cout << "f(miku a,miku b)" << endl;
}

int main() {
    f(8);
    f(1.1);  // 两个可行函数，一个最佳匹配
    // f(2,2.2);    // 多个最佳匹配，二义性
    f(static_cast<miku>(2), 2.2);  // 类型转换
    f(2, static_cast<int>(2.2));
    f(2, static_cast<int>(2.2));

    return 0;
}
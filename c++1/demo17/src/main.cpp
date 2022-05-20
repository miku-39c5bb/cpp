#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s("hello world");
    string* sp = &s;

    cout << s << endl;
    cout << *sp << endl;
    cout << sp << endl;

    vector<int>* pevc;
    int *ip1, *ip2;
    double dp, *dp2;

    int ival = 1024;
    int* pi = 0;  // 指针为0，表示不指向任何对象
    int* pi2 = &ival;
    int* pi3;  // 没有初始化
    pi = pi2;
    pi2 = 0;

    int ival2;
    int zero = 0;
    const int c_ival = 0;

    // int* pi4 = ival;
    // int* pi4 = zero;
    // int* pi4 = c_ival;
    // int* pi5 = 123;
    int* pi6 = NULL;

    double dval;
    double* pd = &dval;
    double* pd2 = pd;

    // int* pi7 = pd;
    // int* pi7 = &dval;

    double obj = 3.14;
    int k;
    void* pv = &obj;
    pv = &k;

    int a = 1;
    int* pa = &a;
    a += 2;
    *pa += 1;
    cout << a << endl;
    cout << *pa << endl;

    return 0;
}
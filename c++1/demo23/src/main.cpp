#include <iostream>
#include <string>

using namespace std;

class Dog {};

int main() {
    int* pia = new int[10];        // 没有初始化
    string* psa = new string[10];  // 默认构造函数初始化
    Dog* pDog = new Dog[10];       // 默认构造函数初始化
    int* pia2 = new int[10]();     //用内置类型的默认值初始化

    cout << *(pia2 + 2) << endl;
    cout << pia2[9] << endl;

    *pia = 9;
    *(pia + 1) = 8;

    *(pia2 + 3) = 6;

    cout << *(pia + 0) << endl;
    cout << *(pia + 1) << endl;
    cout << *(pia2 + 3) << endl;

    for (int* q = pia; q != pia + 10; ++q) {
        *q = 11;
    }
    // 指针是数组的迭代器，最好使用这种方式
    for (const int* q = pia; q != pia + 10; ++q) {
        cout << *q << " ";
    }
    cout << endl;
    for (size_t i = 0; i != 10; ++i) {
        cout << *(pia + i) << " ";
    }
    cout << endl;

    const int* pci_bad = new const int[100]();

    // char arr[0];
    char* cp = new char[0];

    cout << "请输入动态数组的大小：";
    size_t n;
    cin >> n;
    int* p = new int[n];
    for (int* q = p; q != p + n; ++q) {
        *q = 22;
        cout << *q << " ";
    }
    delete[] pia;
    delete[] psa;
    delete[] pDog;
    delete[] pia2;
    delete[] pci_bad;
    delete[] cp;
    delete[] p;
    // 静态数组不需要delete，它是在堆栈上创建的，当函数结束的时候，堆栈上的变量会自动的清除掉

    return 0;
}
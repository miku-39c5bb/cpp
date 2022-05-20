#include <iostream>
#include <string>

using namespace std;

class Dog {
public:
    int amount;  // 最好是自己写一个构造函数，更明确一些
    string name;
};

// Dog a;  // 全局对象，基本数据类型都初始化为0、'\0'、NULL、nullptr等

int main() {
    cout << "hello" << endl;
    // Dog a;   // int型的amount是垃圾值
    static Dog a;  // 类似于全局对象
    cout << a.name << endl;
    cout << a.amount << endl;
    string s("world");
    cout << s << endl;

    return 0;
}
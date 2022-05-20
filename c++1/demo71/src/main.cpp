#include <iostream>
#include <vector>

using namespace std;

class Person {
private:
public:
    int money;

public:
    // 方法①优于方法②
    Person(/* args */) : money(0) {  // 方法①，构造函数的初始化列表
        // money = 0;                // 方法②
    }
    ~Person() {}
};

int main() {
    Person a;
    Person b;

    cout << a.money << endl;
    cout << b.money << endl;

    return 0;
}
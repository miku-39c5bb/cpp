#include <iostream>
#include "../include/Sales_data.h"

using namespace std;

class Person {
    // friend istream& operator>>(istream& in, Person& p);
public:
    // 重载操作符要设为public
    void operator+(const Person& rhs) {
        cout << "执行了重载的加法操作" << endl;
    }
    // void operator||(const Person& rhs) {}
};
// istream& operator>>(istream& in, Person& p) {
//     return in;
// }

int main(int argc, char** argv) {
    int a, b;
    a = 12;
    b = 9;
    cin >> a;
    cout << a + b << endl;

    Person p1, p2;
    p1 + p2;  // 还未重载'+'操作符时，两个自定义类不能相加
    // cin >> p1 >> p2;

    Sales_data item1, item2;
    cin >> item1 >> item2;
    cout << item1 + item2 << endl;

    cout << "Hello World" << endl;
    system("pause");
    return 0;
}
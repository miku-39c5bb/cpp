#include <iostream>
#include <string>
#include "../include/Sales_item.h"
using namespace std;

class Dog {
public:
    Dog(string n, int a, double w)
        : name(n), age(a), weight(w) {}
    operator int() const {
        return age;
    }
    operator double() const {
        return weight;
    }
    operator string() const {
        return name;
    }

private:
    int age;
    double weight;
    string name;
};

int main() {
    int a, b;

    a = 10;
    b = a;

    Dog d("Bill", 6, 15.0);
    b = d;

    double dd = d;
    string str = d;

    cout << b << endl;
    cout << dd << endl;
    cout << str << endl;

    // 输入X-123-7890 10 120.0
    Sales_item item(cin);
    cout << item << endl;

    string s = item;
    double m = item;
    cout << s << endl;
    cout << m << endl;
    cout << item << endl;

    return 0;
}
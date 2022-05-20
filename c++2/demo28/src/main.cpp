#include <iostream>
#include <string>
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

    return 0;
}
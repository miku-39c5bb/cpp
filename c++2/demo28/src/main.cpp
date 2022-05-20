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

    cout << b << endl;

    return 0;
}
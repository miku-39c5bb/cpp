#include <iostream>

using namespace std;

class Dog {
   public:
    void foo() { cout << "Hello World" << endl; }
};

int main() {
    Dog d;
    d.foo();

    Dog* p = new Dog();
    (*p).foo();
    p->foo();

    delete p;

    return 0;
}
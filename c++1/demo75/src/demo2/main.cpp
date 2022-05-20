#include <iostream>
#include <string>

using namespace std;

void print(const string &);
void print(miku);
void print(int);

// void print1(int *a) {}
// void print1(int *const b) {}

void fooBar(int ival) {
    // 这是一个局部函数的声明，发生函数隐藏，只有print(int)有效了
    // void print(int a);

    print("hello");
    print(ival);
    print(3.14);
}

int main() {
    fooBar(16);
    return 0;
}

void print(const string &s) {
    cout << "string: " << s << endl;
}
void print(miku d) {
    cout << "miku: " << d << endl;
}
void print(int i) {
    cout << "int: " << i << endl;
}

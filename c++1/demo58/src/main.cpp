#include <iostream>

using namespace std;

void addOne(int* ip) { *ip = *ip + 1; }
// void addTwo(const int* ip) { *ip = *ip + 2; }
int add(const int* px, const int* py) { return *px + *py; }

void foo(int i) { cout << i << endl; }
// void foo(const int i) { cout << i << endl; }
void foo(double i) { cout << i << endl; }
void foo(int* pi) { cout << pi << endl; }
// void foo(int* const pi) { cout << pi << endl; }
void foo(const int* pi) { cout << pi << endl; }

int main()
{
    int a = 1, b = 2, c = 3;
    const int a2 = 10, b2 = 20, c2 = 30;

    addOne(&a);
    add(&a, &b);
    add(&a2, &b2);

    cout << "Hello World" << endl;
    return 0;
}
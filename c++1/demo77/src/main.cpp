#include <iostream>
#include <vector>

using namespace std;

class Account {
public:
    Account() {}
    Account(int x) : num(x) {}

public:
    int num;
};

enum Tokens { INLINE = 128, VIRTUAL = 129 };

void lookup(Account &x) {
    cout << "lookup(Account&x)" << endl;
}
// void lookup(Account &const x) {  // 重定义：void lookup(Account &x)
//     cout << "lookup(Account&x)" << endl;
// }
void lookup(const Account &x) {
    cout << "lookup(const Account&x)" << endl;
}

void f(int *p) {
    cout << "f(int *p)" << endl;
}
// void f(int *const p) {       // 重定义：void f(int *p)
//     cout << "f(int *p)" << endl;
// }
void f(const int *p) {
    cout << "f(const int *p)" << endl;
}

void newf(unsigned char x) {
    cout << "new(unsigned char x)" << endl;
}
void newf(int y) {
    cout << "newf(int y)" << endl;
}

void ff(Tokens t) {
    cout << "ff(Tokens t)" << endl;
}
void ff(int x) {
    cout << "ff(int x)" << endl;
}
void ff(short x) {
    cout << "ff(short x)" << endl;
}

// void manip(long x) {
void manip(miku x) {
    cout << "manip(miku x)" << endl;
}
void manip(float x) {
    cout << "manip(float x)" << endl;
}

int main() {
    cout << "-----------" << endl;
    const Account a(0);
    Account b(0);
    lookup(a);
    lookup(b);

    cout << "-----------" << endl;
    int m = 5, n = 6;
    int *p = &m;
    const int *p2 = &n;
    f(p);
    f(p2);
    f(&m);
    f(&n);
    const int o = 9;
    f(&o);

    cout << "-----------" << endl;
    unsigned char uc = 129;
    newf(VIRTUAL);  // Tokens -> int
    newf(uc);       // unsigned char

    cout << "-----------" << endl;
    Tokens curTok = INLINE;
    ff(curTok);  // Tokens
    ff(INLINE);  // Tokens

    cout << "-----------" << endl;
    ff(128);  // 128 -> int
    ff('a');  // 'a' -> int

    cout << "-----------" << endl;
    manip(3.14);  // 3.14转成long和float没有优先顺序，有二义性
    // 3.14优先转为miku

    cout << "-----------" << endl;

    system("pause");

    return 0;
}
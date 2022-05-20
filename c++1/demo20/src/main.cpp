#include <iostream>
#include <string>

using namespace std;

typedef string* pString;

void doA(const int* p) {}

int main() {
    string s("Hello");
    pString ps;
    ps = &s;

    const pString cstr = ps;  //
    const string* cstr2;      // 指向常string的指针
    string* const cstr3 = ps;

    cout << *ps << endl;

    double a = 1.2;
    double* p = &a;

    const double pi = 3.14;
    const double* cptr;  // 指向常量的指针
    cptr = &pi;

    cptr = &a;
    // &cptr = 1;

    int errNum = 0;
    int nNum = 0;
    int* const curErr = &errNum;
    // curErr = &nNum;

    const double* const pi_ptr = &pi;
    // pi_ptr = &a;
    // *pi_ptr = 3.14;

    const string s1;
    string const s2;

    return 0;
}
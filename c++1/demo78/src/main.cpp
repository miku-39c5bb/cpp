#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 使用typedef定义一个名为cmpFcn的函数指针类型
typedef bool (*cmpFcn)(const string &, const string &);
typedef int (*PF)(int *, int);

// 注意：这不是声明了一个函数，而是声明了一个变量
// 声明了一个全局变量pf，pf是一个指向函数的指针
bool (*pf)(const string &, const string &);

// pf2是一个函数，返回bool*
bool *f(const string &, const string &);

bool lengthCompare(const string &s1, const string &s2) {
    return s1.size() == s2.size();
}
bool lengthCompare2(string &s1, const string &s2) {
    return s1.size() == s2.size();
}
bool lengthCompare3(const string *s1, const string *s2) {
    return s1->size() == s2->size();
}
bool lengthCompare4(string *s1, const string *s2) {
    return s1->size() == s2->size();
}
bool lengthCompare5(const string *const s1, const string *s2) {
    return s1->size() == s2->size();
}
string::size_type sumLength(const string &s1, const string s2) {
    return s1.size() + s2.size();
}

// 指向函数的指针也可当作函数的形参
void useBigger(const string &s1,
               const string &s2,
               bool (*pf)(const string &, const string &)) {
    cout << pf(s1, s2) << endl;
}

int demo(int *, int) {
    return 12;
}
// ff是一个函数，这个函数有一个参数int x，返回结果是一个指向函数的指针
// 这个函数指针是int (*)(int *, int)
PF ff(int x) {
    cout << x << endl;
    return demo;
}
// int (*ff(int x))(int *, int) {
//     cout << x << endl;
//     return demo;
// }

void ff(vector<miku> vec) {
    cout << "ff(vector<miku> vec)" << endl;
}
void ff(unsigned int *x) {
    cout << "ff(unsigned int *x)" << endl;
}

int main() {
    cout << "--------" << endl;
    // void (*pf6)(int) = ff;
    // miku (*pf6)(unsigned int) = ff;
    void (*pf6)(unsigned int *const) = ff;
    vector<miku> dvec;
    unsigned int x = 1;
    unsigned int *const px = &x;
    pf6(&x);
    void (*pf7)(unsigned int *) = ff;
    pf7(px);
    void (*pf8)(vector<miku> vec) = ff;
    pf8(dvec);
    cout << "--------" << endl;
    int a = 11;
    cout << ff(2)(&a, a) << endl;
    cout << "--------" << endl;
    useBigger("hsacdddi", "function", lengthCompare);
    cout << "--------" << endl;

    // 原来的做法
    // 声明了一个局部变量pf，pf是一个指向函数的指针
    // bool (*pf)(const string &, const string &);
    // bool (*pf2)(const string &, const string &);
    // bool (*pf3)(const string &, const string &);

    // 使用typedef后
    // 用cmpFcn类型定义了三个函数指针
    cmpFcn pf;
    cmpFcn pf2;
    cmpFcn pf3 = 0;
    bool (*pf4)(const string &, const string &) = 0;
    pf3 = lengthCompare;
    cout << pf3("ii", "ww") << endl;
    pf4 = lengthCompare;
    cout << pf4("i", "ww") << endl;

    cout << "-------" << endl;
    bool (*pf5)(const string *, const string *) = 0;
    pf5 = lengthCompare3;
    // pf5 = lengthCompare4;
    // pf5 = lengthCompare5;
    string s1 = "hh", s2 = "ii";
    cout << pf5(&s1, &s2) << endl;
    cout << "-------" << endl;

    // 让 pf 指向 函数lengthCompare()
    // pf = &lengthCompare;
    pf = lengthCompare;

    cout << lengthCompare("hello", "world") << endl;
    // 用指向函数的指针pf调用它所指向的函数
    cout << (*pf)("hello", "world") << endl;
    cout << pf("hello", "world") << endl;

    system("pause");
    return 0;
}
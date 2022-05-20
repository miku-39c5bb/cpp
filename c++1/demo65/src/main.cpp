#include <iostream>
#include <string>

using namespace std;

const int& add_one(const int& x) {
    // ++x;
    return x;
}

string make_plural(size_t ctr, const string& word, const string& ending) {
    // string res;
    // if (ctr > 1) {
    //     res = word + ending;
    // } else {
    //     res = word;
    // }

    // return res;
    return (ctr == 1) ? word : word + ending;
}

const string& shorter_string(const string& s1, const string& s2) {
    return s1.size() < s2.size() ? s1 : s2;
}

const string& manip(const string& s) {
    string ret = s;
    return ret;  // 返回局部对象的引用，很危险
}

int* manip2() {
    int a = 100;
    int* p = &a;
    return p;  // 返回局部对象的指针，很危险
}

int main() {
    int a = 1;
    const int& b = add_one(a);
    cout << a << endl;
    // ++b;
    cout << a << endl;
    cout << b << endl;

    int cnt = 6;
    string res = make_plural(cnt, "dog", "s");
    cout << cnt << " " << res << endl;

    cout << shorter_string("Hello", "Dog") << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

string init() {
    return "Hello";
}

void fcn() {
    // int init = 0;   // 变量名与函数名同名，变量名隐藏了函数名
    string s = init();
    cout << s << endl;
}

int main() {
    fcn();
    return 0;
}
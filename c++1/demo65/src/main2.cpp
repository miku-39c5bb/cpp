#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

char& get_val(string& str, string::size_type ix) {
    return str[ix];
}

int main() {
    string s("hello");
    char& c = get_val(s, 1);
    c = 'i';
    cout << s << endl;

    // c = get_val(s, 0);
    // 返回一个左值
    get_val(s, 0) = 'k';
    cout << s << endl;

    return 0;
}
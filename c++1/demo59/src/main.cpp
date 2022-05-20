#include <iostream>
#include <string>

using namespace std;

void swap(int& v1, int& v2) {
    int temp = v2;
    v2 = v1;
    v1 = temp;
}

int doOp(int x, int y, int& res2) {
    int res;
    res = x + y;
    res2 = x - y;
    return res;
}

bool isShorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

string::const_iterator find_char(const string& s, char c) {
    string::const_iterator iter = s.begin();
    while (iter != s.end() && *iter != c) {
        ++iter;
    }
    return iter;
}

string::size_type find_char2(const string& s, char c) {
    string::size_type i = 0;
    while (i != s.size() && s[i] != c) {
        ++i;
    }
    return i;
}

int main() {
    int i = 10, j = 20;
    cout << i << " " << j << endl;
    swap(i, j);
    cout << i << " " << j << endl;

    int res;
    cout << doOp(i, j, res) << endl;
    cout << res << endl;

    string s1("one");
    string s2("Three");
    bool res2 = isShorter(s1, s2);
    cout << res2 << endl;

    s1 = "onaaseee";
    cout << *find_char(s1, 'e') << endl;
    cout << find_char2(s1, 'e') << endl;

    return 0;
}
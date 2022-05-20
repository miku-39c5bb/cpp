#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    cout << ivec.size() << endl;

    int k = 0;

    cout << "请输入5个整数：";
    for (vector<int>::size_type i = 0; i != 5; ++i) {
        cin >> k;
        ivec.push_back(k);
    }
    for (vector<int>::size_type i = 0; i != ivec.size(); ++i) {
        cout << ivec[i] << "\t";
    }
    cout << endl;

    string word;
    vector<string> text;
    cout << "请输入一些字符串：";
    while (cin >> word) {
        text.push_back(word);
    }
    for (vector<string>::size_type i = 0; i != text.size(); ++i) {
        cout << text[i] << "\t";
    }
    cout << endl;

    return 0;
}
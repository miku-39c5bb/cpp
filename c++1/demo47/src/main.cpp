#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cout << "Enter some words (ctrl+z to end): " << endl;
    while (cin >> word) {
        if (islower(word[0])) {
            continue;
        } else {
            cout << "找到一个第一个字母大写的单词：" << word << endl;
            cout << "其长度是：" << word.size() << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#define NDEBUG

using namespace std;

int main()
{
    string currWord, preWord;
    cout << "Enter some words(ctrl+z to end): " << endl;
    while (cin >> currWord) {
#ifndef NDEBUG
        cout << "调试：" << currWord << endl; // 这是调试用的
#endif
        if (!isupper(currWord[0])) {
            continue;
        }
        if (currWord == preWord) {
            break;
        } else {
            preWord = currWord;
        }
    }
    if (currWord == preWord && !currWord.empty()) {
        cout << "The repeated words: " << currWord << endl;
    } else {
        cout << "No repeated" << endl;
    }

    return 0;
}
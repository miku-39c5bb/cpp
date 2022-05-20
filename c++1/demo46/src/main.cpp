#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;

    srand((unsigned)time(NULL));  // 设置随机数种子

    for (size_t i = 0; i < 100; ++i) {
        vec.push_back(rand() % 101);  // 0~100
    }

    vector<int>::const_iterator iter = vec.begin();
    while (iter != vec.end()) {
        if (*iter == 100) {
            break;
        } else {
            ++iter;
        }
    }
    cout << *iter << endl;
    if (iter != vec.end()) {
        cout << "有人考100分" << endl;
    } else {
        cout << "没有人考100分" << endl;
    }

    return 0;
}
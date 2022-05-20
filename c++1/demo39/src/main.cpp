#include <iostream>
#include <vector>

using namespace std;

int main() {
    for (size_t i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ivec;
    int cnt = 10;
    while (cnt > 0) {
        ivec.push_back(cnt--);
    }
    vector<int>::const_iterator iter = ivec.begin();
    while (iter != ivec.end()) {
        cout << *(iter++) << " ";
        // cout << *iter++ << " ";
    }
    cout << endl;
    // for (vector<int>::const_iterator iter = ivec.begin(); iter != ivec.end();
    //      ++iter) {
    //     cout << *iter << " ";
    // }
    // cout << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int val;
    vector<int> vec;

    // cin >> val;
    // vec.push_back(val);
    while (cin >> val && val != 42) {
        // cin >> val;
        vec.push_back(val);
    }
    for (vector<int>::const_iterator iter = vec.begin(); iter < vec.end();
         ++iter) {
        cout << *iter << endl;
    }

    return 0;
}
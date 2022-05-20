#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename elementType>
class CMultiply {  // 乘法
public:
    // 这次不是谓词
    elementType operator()(const elementType& elem1, const elementType& elem2) {
        return elem1 * elem2;
    }
};

int main() {
    vector<int> a, b;
    for (size_t i = 0; i < 10; i++) {
        a.push_back(i);
    }
    for (size_t i = 100; i < 110; i++) {
        b.push_back(i);
    }

    vector<int> vecResult;
    vecResult.resize(10);
    transform(a.begin(), a.end(), b.begin(), vecResult.begin(), CMultiply<int>());

    for (size_t i = 0; i < vecResult.size(); i++) {
        cout << vecResult[i] << ' ';
    }
    cout << endl;

    cout << "Hello 二元函数对象！" << endl;

    return 0;
}
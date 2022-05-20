#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 一元谓词
// 判断是否为m_Divisor的整数倍
template <typename numberType>
struct IsMultiple {
    numberType m_Divisor;

    IsMultiple(const numberType& divisor) {
        m_Divisor = divisor;
    }

    bool operator()(const numberType& element) const {
        return ((element % m_Divisor) == 0);
    }
};

int main() {
    vector<int> vecIntegers;
    for (size_t i = 25; i <= 100; i++) {
        vecIntegers.push_back(i);
    }

    IsMultiple<int> a(4);
    vector<int>::iterator iElement;
    iElement = find_if(vecIntegers.begin(), vecIntegers.end(), a);
    if (iElement != vecIntegers.end()) {
        cout << "找到了第一个4的整数倍的数是：" << *iElement << endl;
    }

    iElement = find_if(vecIntegers.begin(), vecIntegers.end(), IsMultiple<int>(5));
    cout << "第一个5的倍数是：" << *iElement << endl;

    return 0;
}
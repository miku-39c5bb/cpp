#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//class absInt {
//public:
//	int operator() (int val){}
//};

// 为什么要设计函数对象？——因为C++中的STL算法就是用函数对象的
// 函数对象实际上是一个类，类可以有数据成员，有了数据成员，函数对象就可以保持状态
// 函数对象——函数对象一般用struct，虽然class加上public后也可以
struct absInt {
    // 重载操作符：函数调用操作符
    int operator()(int val) {
        return val < 0 ? -val : val;
    }
};

// 普通的模板函数
template <typename elementType>
void FuncDisplayElement(const elementType& element) {
    cout << element << ' ';
}

// 模板函数对象
template <typename elementType>
struct DisplayElement {
    // 存储状态
    int m_nCount;  // 记录调用了多少次
    DisplayElement() {
        m_nCount = 0;
    }

    void operator()(const elementType& element) {
        ++m_nCount;
        cout << element << ' ';
    }
};

int main() {
    int i = -42;
    absInt absObj;
    unsigned int ui = absObj(i);
    cout << ui << endl;

    vector<int> a;
    for (size_t i = 0; i < 10; i++) {
        a.push_back(i);
    }

    list<char> b;
    for (char c = 'a'; c < 'k'; c++) {
        b.push_back(c);
    }

    // STL算法
    DisplayElement<int> mResult;
    mResult = for_each(a.begin(), a.end(), mResult);
    cout << endl;
    cout << "调用次数：" << mResult.m_nCount << endl;

    for_each(b.begin(), b.end(), DisplayElement<char>());
    cout << endl;

    cout << "Hello 函数对象" << endl;
    return 0;
}
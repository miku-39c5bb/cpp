#include <iostream>
#include <vector>

// vector<int>::iterator iter = v.begin();
// vector<int>::const_iterator i = v.end() - 1;
// begin()操作返回一个迭代器，指向第一个数据，迭代器实际上就是一个指针
// begin()指向第一个元素，end()指向最后一个元素的下一个
using namespace std;

int main()
{
    vector<int> v(10, 8);
    vector<int>::iterator iter = v.begin();
    *iter = 9;
    iter++;
    *iter = 10;

    for (vector<int>::size_type i = 0; i != v.size(); ++i) {
        cout << v[i] << endl;
    }

    cout << "---------------------" << endl;

    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    cout << "---------------------" << endl;
    vector<int>::iterator iter2 = v.begin() + v.size() / 2 - 1;
    *iter2 = 630;
    *(iter2 + 1) = 646;
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    cout << "------------" << endl;
    for (vector<int>::const_iterator i = v.end() - 1; i >= v.begin(); --i) {
        cout << *i << endl;
    }
    cout << "------------" << endl;
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        *i = 100;
    }
    for (vector<int>::const_iterator i = v.end() - 1; i >= v.begin(); --i) {
        cout << *i << endl;
    }
    cout << "------------" << endl;

    return 0;
}
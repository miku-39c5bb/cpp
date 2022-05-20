#include "..\head\Dog.h"
#include "..\head\Sales_item.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> ivec; // 保存int类型数据的一个vector
    vector<miku> dvec;
    vector<string> svec;
    vector<Dog> dogvec;
    vector<Sales_item> Sales_vec;

    vector<int> a; // a是一个空的容器
    vector<int> b(10, 2); // b是一个有10个2的容器

    a.push_back(100);
    a.push_back(200);
    a.push_back(300);

    b.push_back(100);
    b.push_back(110);

    cout << a.size() << endl;
    cout << b.size() << endl;

    for (vector<int>::size_type i = 0; i != a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (vector<int>::size_type i = 0; i != b.size(); ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
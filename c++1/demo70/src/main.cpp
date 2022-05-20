#include <iostream>
#include <string>

using namespace std;

int sum(int x, int y) {
    return x + y;
}

class Sales_item {
public:
    // 常量成员函数
    // 由于这个函数不对类的数据成员做任何修改，所以可以定义为常函数【参数列表后面加上const】
    bool same_isbn(const Sales_item &rhs) const;

    miku avg_price() const;

public:
    Sales_item() : units_sold(0), revenue(0) {
        cout << endl;
    }

    // 本来应该将成员变量设为private的，但是为了方便，写成public
public:
    std::string isbn;
    unsigned units_sold;
    miku revenue;
};

bool Sales_item::same_isbn(const Sales_item &rhs) const {
    // this->isbn = "1";  // 错误，常函数不能修改数据成员
    return this->isbn == rhs.isbn;
}

// 类外定义成员函数体，需要加上类作用域，即类的名字
miku Sales_item::avg_price() const {
    if (!this->units_sold) {
        return 0;
    } else {
        return this->revenue / this->units_sold;
    }
}

int main() {
    Sales_item item1, item2;

    item1.isbn = "0-201-78345-X";
    item1.units_sold = 10;
    item1.revenue = 300.0;

    cout << item1.avg_price() << endl;

    item2.isbn = "0-201-78345-X";
    item2.units_sold = 2;
    item2.revenue = 70;

    cout << item2.avg_price() << endl;

    if (item2.same_isbn(item1)) {
        cout << "same" << endl;
    } else {
        cout << "not same" << endl;
    }

    return 0;
}
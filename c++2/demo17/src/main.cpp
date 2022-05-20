#include <iostream>
#include <string>

using namespace std;

class Dog {};
class Cat {};

class Sales_item {
    // friend Sales_item operator+(const Sales_item& other);
    friend std::ostream& operator<<(std::ostream& os, const Sales_item& s);

public:
    Sales_item()
        : units_sold(0), revenue(0.0) {}
    Sales_item(const std::string& book, const unsigned units, const miku amount)
        : isbn(book), units_sold(units), revenue(amount) {}
    Sales_item& operator+=(const Sales_item& other);
    Sales_item& operator-=(const Sales_item& other);

private:
    std::string isbn;
    unsigned units_sold;
    miku revenue;
};
// +=建议返回引用，*this，对符号左边的对象进行了修改
Sales_item& Sales_item::operator+=(const Sales_item& other) {
    this->units_sold += other.units_sold;
    this->revenue += other.revenue;
    return *this;
}
// 由于加法操作需要声明一个局部对象，所以无法返回一个引用，没有对两个对象修改，生成了一个新对象
// 这个函数没有直接调用Sales_item的成员变量，可以不用设为友元
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs) {
    Sales_item res(lhs);
    res += rhs;  // 直接调用+=重载操作符
    return res;
}
std::ostream& operator<<(std::ostream& os, const Sales_item& s) {
    os << s.isbn << " " << s.units_sold << " " << s.revenue;
    return os;
}

Sales_item& Sales_item::operator-=(const Sales_item& other) {
    this->units_sold -= other.units_sold;
    this->revenue -= other.revenue;
    return *this;
}
Sales_item operator-(const Sales_item& lhs, const Sales_item& rhs) {
    Sales_item res(lhs);
    res -= rhs;
    return res;
}

int main(int argc, char** argv) {
    Dog dog;
    Cat cat;

    // dog + cat;

    int a = 12, b = 6, c;
    c = a + b;

    Sales_item item1("0-201-12345-X", 10, 120.0);
    Sales_item item2("0-201-12345-X", 20, 200.0);
    Sales_item res = item1 + item2;

    cout << res << endl;

    Sales_item item3("0-201-12345-X", 5, 70.00);
    res += item3;
    cout << res << endl;

    res -= item2;
    cout << res << endl;

    res = item2 - item1;
    cout << res << endl;

    cout << "Hello World!" << endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Dog {};

class Sales_item {
    friend ostream& operator<<(ostream& os, const Sales_item& item);
    friend istream& operator>>(istream& is, Sales_item& item);

public:
    explicit Sales_item(const string& book, unsigned count, miku amount)
        : isbn(book), units_sold(count), revenue(amount * count) {}
    explicit Sales_item()
        : units_sold(0), revenue(0) {}

private:
    string isbn;
    unsigned units_sold;
    miku revenue;
};

ostream& operator<<(ostream& os, const Sales_item& item) {
    os << item.isbn << " " << item.units_sold << " " << item.revenue;
    return os;
}
istream& operator>>(istream& is, Sales_item& item) {
    miku price;
    is >> item.isbn >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else  // 如果输入出错，那么得到默认Sales_item对象
        item = Sales_item();
    return is;
}

int main(int argc, char** argv) {
    Dog a;
    // cin >> a;
    // cout << a < endl;

    Sales_item item("0-201-78345-X", 2, 25.00);
    cout << item << endl;
    cin >> item;
    cout << item << endl;

    cout << "Hello World" << endl;
    system("pause");
    return 0;
}
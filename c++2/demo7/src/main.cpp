/*** 
 * @Author: doubledouble
 * @Date: 2022-04-13 01:47:18
 * @LastEditTime: 2022-04-13 13:11:54
 * @LastEditors: doubledouble
 * @Description: 构造函数
 * @FilePath: \c++2\demo7\src\main.cpp
 */

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const std::string& nm, int a)
        : name(nm), age(a) {}

    // private:
public:
    std::string name;
    int age;
};

class Sales_item {
public:
    // 构造函数不要写成const函数
    // Sales_item()
    //     : units_sold(0), revenue(0.0) {}
    explicit Sales_item(const std::string& book = "")  // 加上默认值""后，就可以直接去掉上面那个构造函数了
        : isbn(book), units_sold(0), revenue(0.0) {}
    explicit Sales_item(std::istream& in) {
        in >> *this;
    }
    // 速度慢，不推荐，初始化是一定会有的，不管有没有初始化列表，这种写法会赋值两次
    // 以前的C++不会初始化内置类型，比如int，另一些如string就会在初始化列表初始化
    // 另外，即使没有在初始化列表写类类型（如string），它也会被初始化
    explicit Sales_item(int units, double price) {
        this->units_sold = units;
        this->revenue = price * this->units_sold;
    }
    // 初始化列表的顺序不是真正初始化的顺序，真正的初始化顺序是定义成员变量的顺序
    explicit Sales_item(const std::string& book, int units, double price)
        : isbn(book), units_sold(units), revenue(price * this->units_sold) {}
    bool same_isbn(const Sales_item& other) const {
        return this->isbn == other.isbn;
    }

    friend std::istream& operator>>(std::istream& in, Sales_item& item);

private:
public:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};
inline std::istream& operator>>(std::istream& in, Sales_item& item) {
    double price;
    in >> item.isbn >> item.units_sold >> price;
    if (in) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_item();
    }
    return in;
}

class test {
private:
    const int a;

public:
    // const成员、引用类型成员、没有默认构造函数的类类型成员 必须使用初始化列表
    test()
        : a(16) {}
    void show() {
        std::cout << this->a << std::endl;
        std::cout << this << std::endl;
    }
    ~test() {}
};

class TT {};

class Data {
public:
    int i;
    double d;
};

int main(int argc, char** argv) {
    Data data = {1, 1.2};

    Person a("张飞", 10);
    cout << a.name << endl;
    cout << a.age << endl;

    Sales_item item1;
    cout << item1.isbn << endl
         << item1.units_sold << endl
         << item1.revenue << endl;
    Sales_item item2("162520");
    // if (item2.same_isbn("162520")) {
    // }
    // if (item2.same_isbn(cin)) {
    // }
    Sales_item* p = new Sales_item();

    delete p;

    test t;
    t.show();

    cout << "--------------------------------" << endl;
    // TT tt();
    TT tt;
    TT* ptt = new TT;
    TT* ptt2 = new TT();
    delete ptt;
    delete ptt2;

    return 0;
}
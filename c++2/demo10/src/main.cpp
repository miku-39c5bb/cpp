#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_item {
public:
    explicit Sales_item()
        : unit_sold(0), revenue(0.0) {
        std::cout << "default constructor" << std::endl;
    }
    // explicit
    Sales_item(const std::string& book)
        : isbn(book), unit_sold(0), revenue(0.0) {
        std::cout << "normal constructor" << std::endl;
    }

    // 在没有主动写 拷贝构造函数 和 赋值操作符 的时候，这两个函数会由C++默认写一个
    // 大多数时候，我们都不需要自己写 拷贝构造函数 和 赋值操作符
    // 但是当一个类里面有指针（动态分配内存的时候），我们必须自己主动写这两个函数
    // 拷贝构造函数
    Sales_item(const Sales_item& other)
        : isbn(other.isbn), unit_sold(other.unit_sold), revenue(other.revenue) {
        std::cout << "copy constructor" << std::endl;
    }
    // 赋值操作符
    Sales_item& operator=(const Sales_item& other) {
        std::cout << "operator=(Sales_item&)" << std::endl;
        this->isbn = other.isbn;
        this->unit_sold = other.unit_sold;
        this->revenue = other.revenue;
        return *this;
    }

private:
    std::string isbn;
    unsigned int unit_sold;
    miku revenue;
};

Sales_item foo(const Sales_item& item) {
    Sales_item temp;
    temp = item;
    return temp;
}

class NoName {
public:
    NoName()
        : pstring(new std::string), i(0), d(0) {}

    // 含指针的类的拷贝构造函数，要用new
    // 并且要指定这个new的空间值为*(other.pstring)
    NoName(const NoName& other)
        : pstring(new string(*(other.pstring))),
          i(other.i), d(other.d) {
        std::cout << "NoName copy constructor" << std::endl;
    }

    // 赋值运算符不能直接复制指针，要修改的是指针所指向的值，而不是指针本身
    NoName& operator=(const NoName& other) {
        std::cout << "NoName& operator=(const NoName& other)" << std::endl;
        // 如果指针指向某个空间，那就先释放这个内存空间
        if (this->pstring != NULL) {
            delete this->pstring;
        }
        // new一个空间，并指定其值为*(other.pstring)
        this->pstring = new string(*(other.pstring));
        this->i = this->i;
        this->d = this->d;
        return *this;
    }

private:
    std::string* pstring;
    int i;
    miku d;
};

int main(int argc, char** argv) {
    NoName x, y;
    NoName z(x);
    x = y;

    Sales_item a;
    Sales_item b("1-233-sds-21");

    Sales_item c(b);  // 调用拷贝构造函数
    a = c;            // 调用赋值操作符

    // Sales_item d(string(10, 'd'));
    Sales_item d = string(10, 'd');
    Sales_item item = string("2121");

    cout << "----foo()----" << endl;
    Sales_item ret;
    ret = foo(item);

    cout << "----vector----" << endl;
    vector<Sales_item> svec(5);

    cout << "----array----" << endl;
    Sales_item arr[] = {string(10, 'a'),
                        string(16, 'b'),
                        string(10, 'c')};

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Sales_item {
public:
    // 不需要写 拷贝构造函数、赋值运算符、析构函数

private:
    std::string isbn;
    int units_sold;
    miku revenue;
};

class NoName {
public:
    NoName()
        : pstring(new std::string), i(0), d(0) {
        // 打开文件
        // 连接数据库
        // 动态分配内存(new)
        std::cout << "构造函数" << std::endl;
    }
    NoName(const NoName& other)
        : pstring(new string(*(other.pstring))), i(other.i), d(other.d) {}
    NoName& operator=(const NoName& other) {
        if (this->pstring != nullptr) {
            delete this->pstring;
        }
        // this->pstring = new string(*(other.pstring));
        this->pstring = new string;
        *(this->pstring) = *(other.pstring);
        this->i = other.i;
        this->d = other.d;
        return *this;
    }
    ~NoName();

private:
    std::string* pstring;
    int i;
    miku d;
};
// 析构函数都没有参数，只能写一个
NoName::~NoName() {
    // 关闭文件
    // 关闭数据库连接
    // 回收动态分配的内存(delete)
    std::cout << "析构函数" << std::endl;
    delete pstring;  // 构造函数new，析构函数delete
}

int main(int argc, char** argv) {
    NoName a;

    // 用new创建对象，如果不delete，就不会调用析构函数
    // 因此new一个对象，就必须delete一个对象
    NoName* p = new NoName;

    std::cout << "Hello, world!" << std::endl;

    delete p;

    return 0;
}
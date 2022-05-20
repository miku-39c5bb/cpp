/*** 
 * @Author: doubledouble
 * @Date: 2022-04-11 20:26:07
 * @LastEditTime: 2022-04-13 01:43:10
 * @LastEditors: doubledouble
 * @Description: 类作用域
 * @FilePath: \c++2\demo6\src\main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

void doA() {
    int a;
    a = 12;
}
void doB() {
    int b;
    b = 99;
}

class First {
public:
    int memi;
    double memd;

public:
    void doC() {
        memi = 22;
    }
    void doD() {
        doC();
    }
};

int height /* ① */;
class ScreenB {
public:
    typedef std::string::size_type index;
    void dummy_fcn(index height /* ② */) {
        cursor = width * height;  // 这是哪个height，②
        // 上面这句中的height是②，因为③隐藏了①，②又隐藏了③
        cursor = width * this->height;  // this指针，③
        cursor = width * ::height;      // ::全局作用域，①
        // ①全局作用域
        // ③类作用域
        // ②函数作用域
    }

private:
    index cursor;
    index height /* ③ */, width;
};

class ScreenA {
public:
    typedef std::string::size_type index;
    char get(index r, index c) const;
    index get_cursor() const;

private:
    std::string contents;
    index cursor;
    index height, width;
};
char ScreenA::get(index r, index c) const {
    index row = r * width;
    return contents[row + c];
}
// 这里的返回类型必须写上类作用域
// 第二个ScreenA::只表明了这个作用域包括后面的部分，没有包括前面的返回类型
ScreenA::index ScreenA::get_cursor() const {
    return cursor;
}

int main(int argc, char** argv) {
    ScreenA::index ht;

    doA();
    doB();

    First obj;
    First* ptr = &obj;
    ptr->doC();
    obj.memi = 12;
    ;
    return 0;
}
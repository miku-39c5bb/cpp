#include <iostream>
#include <string>
using namespace std;

class Window_Mgr;
class Screen;

class Dog {
public:
    // Screen需要有定义才行，可以将foo()的函数写在后面
    int foo(Screen& screen);
    int koo(Screen& screen);
};

class Screen {
public:
    // 友元函数
    friend int calcArea(Screen&);
    // 友元类
    friend Window_Mgr;
    // 将Dog类的成员函数foo()声明为友元，需要先有Dog的定义才行
    friend int Dog::foo(Screen&);
    friend Dog::koo(Screen&);

    typedef std::string::size_type index;

    explicit Screen(int ht = 0, int wd = 0)
        : contents(ht * wd, ' '), cursor(0), height(ht), width(wd) {}

    int area() const {
        return height * width;
    }

private:
    std::string contents;
    index cursor;
    int height, width;
};

// 这不是类的成员函数
// 定义为友元函数后，可以使用类的私有成员
int calcArea(Screen& screen) {
    return screen.height * screen.width;
}

// 友元类
class Window_Mgr {
public:
    void relocate(int r, int c, Screen& s) {
        s.height += r;
        s.width += c;
    }
};

int Dog::foo(Screen& screen) {
    return screen.height * screen.width;
}
int Dog::koo(Screen& screen) {
    return screen.height * screen.width;
}

int main(int argc, char** argv) {
    Screen a(60, 100);
    cout << a.area() << endl;

    Window_Mgr wm;
    wm.relocate(20, 100, a);

    Dog dog;
    cout << dog.foo(a) << endl;

    cout << calcArea(a) << endl;

    return 0;
}
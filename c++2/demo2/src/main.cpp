#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
    // 2. 类型别名，简化代码
    typedef std::string::size_type index;  // 这个类型是公有的，类外也可以用

    // 4. ①定义在类内部——内联函数 2. 使用类型别名
    Screen(index ht = 10, index wd = 10)
        : contents(ht * wd, 'A'), cursor(0),
          height(0), width(0) {}
    Screen(index ht, index wd, const std::string& conts);

    // 3. 重载
    char get() const;

    // 3. 重载 2. 使用类型别名
    char get(index r, index c) const;

private:
    std::string contents;  // 内容
    index cursor;          // 光标的位置
    index height, width;   // 屏幕的宽度和高度
};

Screen::Screen(index ht, index wd, const std::string& conts)
    : contents(conts), cursor(0),
      height(ht), width(wd) {}

// 4. ③定义在类外部，但是定义前面有inline——显式声明的内联函数
inline char Screen::get() const {
    return contents[cursor];
}

// 4. ②定义在类外部——不是内联函数
char Screen::get(index r, index c) const {
    index row = r * width;
    return contents[row + c];
}

int main(int argc, char** argv) {
    Screen screen(16, 30);
    cout << screen.get() << endl;
    cout << screen.get(1, 1) << endl;
    cout << screen.get(2, 16) << endl;

    Screen screen2(16, 30, "wjh520double20169");
    cout << screen2.get() << endl;
    cout << screen2.get(0, 6) << endl;

    Screen::index i = 0;
    cout << i << endl;

    return 0;
}
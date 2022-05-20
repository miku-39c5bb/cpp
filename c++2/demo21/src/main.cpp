#include <cstring>
#include <iostream>

using namespace std;

class String {
public:
    explicit String(const char* chars = "");
    // 可变成员函数（返回引用，不加const）——由普通对象调用
    char& operator[](std::size_t index);
    // 常量成员函数（返回普通变量，加上const）——由const对象调用
    char operator[](std::size_t index) const;
    // 下面这个函数可以直接代替上面两个函数（既返回引用，又是const函数）
    // char& operator[](std::size_t index) const;
    void print() const;

private:
    char* ptrChars;
    static String errorMessage;
};
String String::errorMessage("index out of range");

String::String(const char* chars) {
    chars = chars ? chars : "";
    ptrChars = new char[strlen(chars) + 1];
    std::strcpy(ptrChars, chars);
}
char& String::operator[](size_t index) {
    if (index >= std::strlen(ptrChars)) {
        throw errorMessage;
    }
    return ptrChars[index];
}
char String::operator[](std::size_t index) const {
    if (index >= std::strlen(ptrChars)) {
        throw errorMessage;
    }
    return ptrChars[index];
}
void String::print() const {
    cout << ptrChars << endl;
}

int main(int argc, char** argv) {
    String s("wjh 520 double 20169");
    // cout << s[5] << endl;
    s.print();

    String t("test");
    cout << t[0] << endl;
    t.print();
    t[1] = '1';
    t.print();

    const String c("const");
    cout << c[2] << endl;  // 调用const成员函数

    cout << "Hello World" << endl;
    system("pause");
    return 0;
}
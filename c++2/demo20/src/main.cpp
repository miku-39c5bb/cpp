#include <cstring>
#include <iostream>

using namespace std;

class String {
public:
    String(char const* chars = "");

    // 三个常用赋值运算符
    String& operator=(const String&);
    // 这两个也需要重载，但是本例略过
    String& operator=(const char*);
    String& operator=(char);

    void print();

private:
    char* ptrChar;
};
String::String(char const* chars) {
    chars = chars ? chars : "";                  // 如果chars是NULL指针，置为空字符串""
    ptrChar = new char[std::strlen(chars) + 1];  // '\0'，+1
    std::strcpy(ptrChar, chars);
}
String& String::operator=(const String& str) {
    // 如果字符串长度不相同，需要重新new空间
    if (std::strlen(ptrChar) != std::strlen(str.ptrChar)) {
        delete[] ptrChar;  // 注意先delete原来的空间，再重新new
        ptrChar = new char[std::strlen(str.ptrChar) + 1];
    }
    std::strcpy(ptrChar, str.ptrChar);
    return *this;
}
void String::print() {
    cout << ptrChar << endl;
}

int main(int argc, char** argv) {
    String s("hello");
    s.print();
    String s1("wjh");
    s1.print();
    s = s1;
    s.print();
    s1.print();

    system("pause");
    return 0;
}
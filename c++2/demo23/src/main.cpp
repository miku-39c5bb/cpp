#include <cstring>
#include <iostream>
using namespace std;

class String {
public:
    String(const char* chars = "");
    String(const String& str);
    ~String();
    void display() const;

    String& operator++();          // 前++
    String const operator++(int);  // 后++

    String& operator--();
    String const operator--(int);

private:
    char* ptrChars;
};
String::String(const char* chars) {
    chars = chars ? chars : "";
    ptrChars = new char[std::strlen(chars) + 1];
    std::strcpy(ptrChars, chars);
}
String::String(const String& str) {
    ptrChars = new char[std::strlen(str.ptrChars) + 1];
    std::strcpy(ptrChars, str.ptrChars);
}
String::~String() {
    delete[] ptrChars;
}
void String::display() const {
    std::cout << ptrChars << std::endl;
}
String& String::operator++() {
    for (std::size_t i = 0; i < std::strlen(ptrChars); ++i) {
        ++ptrChars[i];
    }
    return *this;
}
String const String::operator++(int) {
    String copy(*this);
    ++(*this);
    return copy;
}
String& String::operator--() {
    for (std::size_t i = 0; i < std::strlen(ptrChars); ++i) {
        --ptrChars[i];
    }
    return *this;
}
String const String::operator--(int) {
    String copy(*this);
    --(*this);
    return copy;
}

int main() {
    String s("ABC");
    s.display();
    s++.display();
    (++s).display();
    s--.display();
    (--s).display();

    system("pause");
    return 0;
}
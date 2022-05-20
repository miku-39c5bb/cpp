#include "../include/string.h"
#include <cstring>
#include <iostream>
#include <string>

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
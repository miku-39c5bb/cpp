#include "../include/pointer.h"
#include "../include/string.h"

Pointer::Pointer()
    : ptr(0) {}
Pointer::Pointer(const String& str) {
    ptr = new String(str);
}
Pointer::~Pointer() {
    delete ptr;
}

String Pointer::errorMessage("Uninitialized pointer");

String& Pointer::operator*() {
    if (!ptr)
        throw errorMessage;
    return *ptr;
}
String* Pointer::operator->() const {
    if (!ptr)
        throw errorMessage;
    return ptr;
}
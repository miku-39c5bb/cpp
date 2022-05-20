#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // const char* pc = "a very long literal string";
    // const size_t len = strlen(pc);  // 长度+1，因为有个'\0'

    // for (size_t i = 0; i < 10; ++i) {
    //     char* pc2 = new char[len + 1];
    //     strncpy(pc2, pc, len + 1);
    //     // strncpy(pc2, pc, len);
    //     // strcpy(pc2, pc);

    //     cout << pc2 << endl;

    //     delete[] pc2;
    // }
    const char* pc = "a very long literal string";
    const size_t len = strlen(pc);
    for (size_t i = 0; i < 100; ++i) {
        char* pc2 = new char[len + 1];
        strncpy(pc2, pc, len + 1);
        cout << "C: " << pc2 << endl;
        delete[] pc2;
    }

    string str("a very long literal string");
    for (size_t i = 0; i < 100; ++i) {
        string str2(str);
        cout << "C++: " << str2 << endl;
    }

    return 0;
}
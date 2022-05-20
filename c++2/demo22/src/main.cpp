#include <iostream>
#include "../include/pointer.h"
#include "../include/string.h"
using namespace std;

int main() {
    String s("Hello String");
    s.display();

    String* ps = &s;
    ps->display();

    try {
        Pointer p1("C++");
        p1->display();

        String s = *p1;
        s.display();

        Pointer p2;
        p2->display();
    } catch (String const& error) {
        error.display();
    }

    cout << "Hello, world!" << endl;
    system("pause");
    return 0;
}
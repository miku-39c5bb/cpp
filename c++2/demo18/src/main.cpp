#include <iostream>
#include "../include/Sales_data.h"

using namespace std;

class Person {
};

int main(int argc, char** argv) {
    // Person a("646", "wjh");
    // Person b("646", "WJH");
    // if (a == b) {
    // }

    Sales_data a("123", 10, 120.0);
    Sales_data b("123", 10, 120.0);
    if (a == b) {
        cout << "a == b" << endl;
    }

    return 0;
}
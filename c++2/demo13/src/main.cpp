#include <iostream>

#include "../include/plain_ptr.h"
#include "../include/smart_ptr.h"
#include "../include/value_ptr.h"

using namespace std;

void test_AHasPtr() {
    int i = 42;
    AHasPtr p1(&i, 42);
    AHasPtr p2 = p1;
    cout << p1.get_ptr_val() << endl;
    cout << p2.get_ptr_val() << endl;

    p1.set_ptr_val(0);
    cout << p1.get_ptr_val() << endl;
    cout << p2.get_ptr_val() << endl;

    int* ip = new int(42);
    AHasPtr ptr(ip, 10);
    cout << ptr.get_ptr_val() << endl;
    delete ip;                          // ip变成了野指针（悬垂指针）
    cout << ptr.get_ptr_val() << endl;  // 输出垃圾值
}

void test_CHasPtr() {
    int obj = 16;

    CHasPtr ptr1(obj, 42);
    CHasPtr ptr2(ptr1);
    cout << ptr1.get_ptr_val() << " " << ptr1.get_int() << endl;
    cout << ptr2.get_ptr_val() << " " << ptr2.get_int() << endl;

    ptr1.set_ptr_val(10);
    cout << ptr1.get_ptr_val() << " " << ptr1.get_int() << endl;
    cout << ptr2.get_ptr_val() << " " << ptr2.get_int() << endl;
}

void test_BHasPtr() {
    int obj = 16;

    BHasPtr ptr1(&obj, 42);
    BHasPtr ptr2(ptr1);
    cout << ptr1.get_ptr_val() << " " << ptr1.get_int() << endl;
    cout << ptr2.get_ptr_val() << " " << ptr2.get_int() << endl;

    ptr1.set_ptr_val(10);
    cout << ptr1.get_ptr_val() << " " << ptr1.get_int() << endl;
    cout << ptr2.get_ptr_val() << " " << ptr2.get_int() << endl;
}

int main(int argc, char** argv) {
    cout << "-----浅拷贝-------" << endl;
    test_AHasPtr();

    cout << "-----深拷贝-------" << endl;
    test_CHasPtr();

    cout << "----智能指针-----" << endl;
    test_BHasPtr();

    return 0;
}
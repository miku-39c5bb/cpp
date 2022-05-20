#include <iostream>

using namespace std;

void test() {
    int i(1024);
    int* pi = new int(1024);

    string s(10, '9');                 // 堆栈
    string* ps = new string(10, '9');  // 自由存储区

    delete pi;
    delete ps;
}

void test2() {
    int* pi = new int;     // 没有初始化
    int* pi2 = new int();  // 默认初始化

    delete pi;
    delete pi2;
}

void test3() {
    int i;
    int* pi = &i;
    string str = "hello";
    miku* pd = new miku(33);

    // 不是动态创建的不要delete
    // delete str;

    // 可以编译，但这是一个错误，pi是一个指针，但它指向的不是一个动态创建的对象
    // delete pi;

    delete pd;  // 有一个new，就要有一个相应的delete
}

void test4() {
    int* p = new int(1024);

    delete p;  // delete把动态创建的对象删除了，p还是保存原来的地址
    // delete p;  // 不能多次delete
    // *p = 99;  // 指针delete后，再解引用是很危险的操作
    p = nullptr;  // 好习惯：为了防止上面这种错误发生，最好将delete后的指针置为nullptr
}

void test5() {
    const int* pci = new const int(1024);
    const string* pcs = new const string();

    delete pci;
    delete pcs;
}

class Dog {};

int main() {
    int i;              // 静态创建对象，对象名：i
    int* pi = new int;  // 动态创建对象，没有名字，只有通过指针操作

    i = 12;
    *pi = 12;

    string* ps = new string;     // 默认构造函数
    string* ps2 = new string();  // 默认构造函数

    Dog dog;
    Dog dog2();
    Dog* pdog = new Dog;
    Dog* pdog2 = new Dog();

    delete pi;  // new了的对象一定要delete
    delete ps;
    delete ps2;
    delete pdog;
    delete pdog2;

    test();
    test2();
    test3();
    test4();
    test5();
    cout << "OK!" << endl;

    return 0;
}
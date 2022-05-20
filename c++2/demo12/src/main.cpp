#include <cstring>
#include <iostream>

using namespace std;

class CDemo {
public:
    CDemo(int pa, char* cstr) {
        this->a = pa;
        this->str = new char[1024];
        strcpy(this->str, cstr);
    }

    // 我没写赋值构造函数，C++会自动帮忙写一个复制构造函数（浅复制）
    // 但是我们希望是深复制，即new一个，而不是直接复制指针
    // CDemo(const CDemo& other) {  // 浅复制，C++自己写的复制构造函数大概是这样的
    //     this->a = other.a;
    //     this->str = other.str;
    // }
    CDemo(const CDemo& other) {
        this->a = other.a;
        this->str = new char[1024];
        if (this->str)
            strcpy(this->str, other.str);
    }

    ~CDemo(){
        delete this->str;
    }

private:
public:
    int a;
    char* str;
};

int main(int argc, char** argv) {
    CDemo A(10, "hello");
    cout << "A: ";
    cout << A.a << ", " << A.str << endl;

    CDemo B = A;
    // CDemo B(A);
    cout << "B: ";
    cout << B.a << ", " << B.str << endl;
    B.a = 8;
    cout << "A: ";
    cout << A.a << ", " << A.str << endl;
    cout << "B: ";
    cout << B.a << ", " << B.str << endl;
    B.str[0] = 'd';
    // B.str = "miku";
    cout << "A: ";
    cout << A.a << ", " << A.str << endl;
    cout << "B: ";
    cout << B.a << ", " << B.str << endl;

    return 0;
}
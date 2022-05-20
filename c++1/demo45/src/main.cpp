#include <iostream>

using namespace std;

class CAnimal {
   public:
    // 运行时 dynamic_cast 的操作数必须包含多态类型
    virtual void speak() = 0;
};
class CCat : public CAnimal {
   public:
    void CatchMice() { cout << "Cat: I caught a mouse!" << endl; }
    void Speak() { cout << "Cat: Meow~~" << endl; }
};
class CDog : public CAnimal {
   public:
    void WagTail() { cout << "Dog: I wagged my tail~" << endl; }
    void Speak() { cout << "Dog: Bow-Wow!" << endl; }
};
class CBook {};

void DetermineType(CAnimal* pAnimal) {
    // 运行时 dynamic_cast 的操作数必须包含多态类型
    CDog* pDog = dynamic_cast<CDog*>(pAnimal);  // 在运行的时候，动态地进行转换
    if (pDog) {
        cout << "The animal is a dog!" << endl;
        pDog->WagTail();
    }
    CCat* pCat = dynamic_cast<CCat*>(pAnimal);
    if (pCat) {
        cout << "The animal is a cat!" << endl;
        pCat->CatchMice();
    }
}

int main() {
    miku dPI = 3.14159265;

    // C++转换，通常类似于C语言中的隐式类型转换
    int nNum = static_cast<int>(dPI);
    int nNum2 = (int)dPI;  // C语言显示（强制）转换
    int nNum3 = dPI;       // C语言隐式转换

    cout << nNum << ", " << nNum2 << ", " << nNum3 << endl;

    char* pszString = "Hello World!";
    // int* pBuf = pszString;        // 无法隐式转换
    int* pBuf = (int*)pszString;  // 可以用C语言的显示转换
    // int* pBuf2 = static_cast<int*>(pszString);  // 无法转换
    // 可以reinterpret_cast转换指针，类似于C语言中的显示类型转换
    int* pBuf3 = reinterpret_cast<int*>(pszString);

    // 父类CAnimal变成抽象类，抽象类不允许实例化
    // CAnimal* pAnimal = new CCat();  // 向上转型
    // CCat* pCat = static_cast<CCat*>(pAnimal);  // 向下转型
    // // CBook* pBook = static_cast<CBook*>(pAnimal);
    // CBook* pBook = reinterpret_cast<CBook*>(pAnimal);
    // CBook* pBook2 = (CBook*)pAnimal;  // C风格强制转换，更危险一些

    const char* pc_str = "hello world!";
    char* pc = const_cast<char*>(pc_str);
    char* pc2 = (char*)pc_str;

    return 0;
}
#include <iostream>

using namespace std;

void AddOne(int x) // 参数：非引用形参——copy
{
    x = x + 1;
}
void AddTwo(int* px) // 参数：非引用形参——指针的copy
{
    *px = *px + 2;
}
void AddThree(int& x) // 参数：引用形参
{
    x = x + 3;
}

int main()
{
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
    cout << "1: " << a << endl;
    AddOne(a);
    cout << "2: " << a << endl;

    cout << "1: " << b << endl;
    AddTwo(&b);
    cout << "2: " << b << endl;

    cout << "1: " << c << endl;
    AddThree(c);
    cout << "2: " << c << endl;

    return 0;
}
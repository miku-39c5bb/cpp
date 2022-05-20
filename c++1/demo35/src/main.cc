#include <iostream>

using namespace std;

int main()
{
    char *cp = "Hello World";
    // 检查cp不是空指针
    // 检查*cp这个字符不是null, '\0'
    while (cp && *cp)
    {
        cout << *cp;
        ++cp;
    }
    cout << endl;

    return 0;
}
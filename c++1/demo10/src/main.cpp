#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<32> a(156);
    cout << a << endl;

    bool is_set = a.any(); // any()存在为1的二进制位——真
    cout << is_set << endl;

    bool is_not_set = a.none(); // none()一个1都没有——真
    cout << is_not_set << endl;

    size_t bits_set = a.count(); // count()返回1的个数
    cout << bits_set << endl;

    cout << a.size() << endl;
    cout << a.size() - a.count() << endl;

    return 0;
}
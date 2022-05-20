#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<32> a; // a的大小是32位二进制，全部都是0
    cout << a << endl;

    bitset<16> b(0xffff); // 1111 1111 1111 1111
    cout << b << endl;

    bitset<32> c(0xffff); // 0000 0000 0000 0000 1111 1111 1111 1111
    cout << c << endl;

    bitset<128> d(0xffff);
    cout << d << endl;

    bitset<32> e(156);
    cout << e << endl;

    string str("11110100101101010001");
    bitset<32> f(str, 5, 4);
    cout << f << endl;

    bitset<32> g(str, str.size() - 4);
    cout << g << endl;
    return 0;
}
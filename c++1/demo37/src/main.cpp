#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<30> a;    // 30位
    unsigned long b; // 32位

    a.set(27); // 第27位设为1
    b |= (1UL << 27);

    a.reset(22); // 第22位设为0
    b &= ~(1UL << 22);

    bool status;
    status = a[27]; // 检查第27位是否为1
    cout << status << endl;
    status = b & (1UL << 27);
    cout << status << endl;

    bool status2;
    status2 = a[22];
    cout << status2 << endl;
    status2 = b & (1UL << 22);
    cout << status2 << endl;

    return 0;
}
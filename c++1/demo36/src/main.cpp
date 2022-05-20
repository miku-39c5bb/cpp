#include <iostream>

using namespace std;

int main()
{
    int a = -127;

    // 八进制， unsigned char 8位
    unsigned char bits = 0227; // (0) 10010111 -> 151
    bits = ~bits;              // (1) 01101000 -> 104
    cout << (int)bits << endl;

    bits = 1;   // 00000001
    bits <<= 1; // 00000010
    cout << (int)bits << endl;
    bits <<= 2; // 00001000
    cout << (int)bits << endl;

    bits = 64;  // 01000000
    bits >>= 3; // 00001000
    cout << (int)bits << endl;

    unsigned char b1 = 0145;        // 01100101
    unsigned char b2 = 0257;        // 10101111
    unsigned char result = b1 & b2; // 00100101
    cout << (int)result << endl;

    result = b1 | b2; // 11101111
    cout << (int)result << endl;

    result = b1 ^ b2;            // 11001010
    cout << (int)result << endl; // 312

    return 0;
}
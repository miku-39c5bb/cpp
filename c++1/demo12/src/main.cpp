#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bitset<4> fourBits;
    cout << fourBits << endl;

    bitset<5> fiveBits(string("10101"));
    cout << fiveBits << endl;

    bitset<8> eightBits(255);
    cout << eightBits << endl;

    return 0;
}
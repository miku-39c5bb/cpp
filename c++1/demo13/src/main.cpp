#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<8> eightBits;
    cout << "Enter a 8-bit sequence: ";
    cin >> eightBits;
    cout << endl;

    cout << eightBits << endl;

    cout << "1: " << eightBits.count() << endl;
    cout << "0: " << eightBits.size() - eightBits.count() << endl;

    bitset<8> flipInput(eightBits);
    cout << flipInput << endl;
    flipInput.flip();
    cout << flipInput << endl;

    bitset<8> eightMoreBits;
    cout << "Enter another 8-bit sequence: ";
    cin >> eightMoreBits;
    cout << endl;

    cout << "============" << endl;
    cout << eightBits << endl
         << eightMoreBits << endl;
    cout << "============" << endl;
    cout << (eightBits & eightMoreBits) << endl; // 位与
    cout << (eightBits | eightMoreBits) << endl; // 位或
    cout << (eightBits ^ eightMoreBits) << endl; // 位异或

    return 0;
}
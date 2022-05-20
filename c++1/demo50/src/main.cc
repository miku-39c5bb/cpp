#include <bitset>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
    try {
        string s("10ab110010");
        // string s("1010110010");
        bitset<10> b(s);
        cout << "bitset ok" << endl;
    } catch (invalid_argument err) {
        cout << "bitset error: " << err.what() << endl;
    }

    return 0;
}
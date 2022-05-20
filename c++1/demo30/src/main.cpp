#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "输入两个整数：";

    cin >> a >> b;
    if (a > b) {
        cout << a << " > " << b << endl;
    } else if (a < b) {
        cout << a << " < " << b << endl;
    } else {
        cout << a << " == " << b << endl;
    }

    return 0;
}
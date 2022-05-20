#include <iostream>

using namespace std;

int main() {
    bool rain;
    rain = true;

    if (rain) {
        cout << "现在下雨了" << endl;
    }
    if (rain == true) {
        cout << "现在下雨了" << endl;
    }

    int val = 18;
    if (val == 1) {
        cout << "val == 1" << endl;
    }
    if (val) {
        cout << "val == 1" << endl;
    }

    return 0;
}
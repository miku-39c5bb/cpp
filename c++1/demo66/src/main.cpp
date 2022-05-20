#include <iostream>

using namespace std;

void doA() {
    cout << "Hello" << endl;
    doA();
}

int getAnswer(int n) {
    if (n == 0) {
        return 1;
    }
    return n * getAnswer(n - 1);
}

int getAnswer2(int n) {
    int res = 1;
    for (int i = n; i > 0; --i) {
        res *= i;
    }
    return res;
}

int main() {
    // doA();
    cout << getAnswer(5) << endl;
    for (size_t num = 0; num < 10; num++) {
        cout << getAnswer(num) << endl;
    }

    return 0;
}
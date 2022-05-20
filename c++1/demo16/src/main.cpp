#include <iostream>

using namespace std;

int main() {
    const size_t array_size = 7;
    int ia[] = {10, 20, 30, 40, 50, 60, 70};
    int ia2[array_size];

    for (size_t i = 0; i < 7; i++) {
        cout << ia[i] << " ";
    }
    cout << endl;

    // ia2 = ia;
    for (size_t i = 0; i < array_size; i++) {
        ia2[i] = ia[i];
    }

    for (size_t i = 0; i < 7; i++) {
        cout << ia2[i] << " ";
    }

    return 0;
}
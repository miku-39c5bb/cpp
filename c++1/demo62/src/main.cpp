#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // for (size_t i = 0; i != argc; ++i) {
    //     cout << argv[i] << endl;
    // }

    int start, end, step;
    start = atoi(argv[1]);
    end = atoi(argv[2]);
    step = atoi(argv[3]);
    for (size_t k = start; k <= end; k += step) {
        cout << k << endl;
    }

    return 0;
}
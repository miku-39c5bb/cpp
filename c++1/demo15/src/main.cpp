#include <iostream>
#include <string>

using namespace std;

unsigned get_size() {
    int a = 100;
    int b = 200;
    return a + b;
}

int main() {
    int a[100];

    const unsigned buf_size = 512, max_files = 20;
    int staff_size = 27;

    const unsigned sz = get_size();

    char input_buffer[buf_size];
    string fileTabel[max_files + 1];

    // 数组的维数必须是编译时就能确定的数字（常量）
    // double salaries[staff_size];
    // int test_scores[get_size()];
    // int vals[sz];

    const unsigned array_size = 3;
    int ia[array_size] = {12, 9, 37};
    // int ib[3] = {1, 2, 3, 4, 5};
    int ib[5] = {1, 2, 3};
    cout << sizeof(ia) / sizeof(ia[0]) << endl;
    cout << sizeof(ia) << endl;

    for (int i : ia) {
        cout << i << "\t";
    }
    cout << endl;
    for (int i : ib) {
        cout << i << "\t";
    }
    cout << endl;

    string str_arr[5] = {"hi", "bye"};
    char ca1[] = {'C', '+', '+'};
    char ca2[] = {'C', '+', '+', '\0'};
    char ca3[] = "C++";

    // const char ca4[6] = "Daniel";

    cout << "OK!" << endl;

    return 0;
}
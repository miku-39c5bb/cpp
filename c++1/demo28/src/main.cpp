#include <iostream>

using namespace std;

typedef int int_array[4];

int main() {
    const size_t rowSize = 3;
    const size_t colSize = 4;
    // int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int ia[rowSize][colSize] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    // int ia[3][4] = {{1}, {2}, {3, 2}};

    for (size_t i = 0; i != rowSize; ++i) {
        for (size_t j = 0; j != colSize; ++j) {
            cout << ia[i][j] << "\t";
        }
        cout << endl;
    }

    // ip是一个指针，指向有4个int的数组
    // *ip指向这个数组的第一个元素【相当于数组名】
    // int(*ip)[4];
    int_array* ip;  // 等价于int(*ip)[4];
    ip = ia;
    for (int* q = *ip; q != *ip + 4; ++q) {
        cout << *q << " ";
    }
    cout << endl;
    ip = &ia[2];
    for (int* q = *ip; q != *ip + 4; ++q) {
        cout << *q << " ";
    }
    cout << endl;

    // 数组不能复制，所以只能用int_array*
    for (int_array* p = ia; p != ia + 3; ++p) {
        for (int* q = *p; q != *p + 4; ++q) {
            cout << *q << "\t";
        }
        cout << endl;
    }

    return 0;
}
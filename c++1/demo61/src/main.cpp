#include <iostream>

using namespace std;

// 字符数组（C风格字符串），最后一个是'\0'【即null】，所以不需要传入数组大小size
// x是指针，指向第一个字符
void printChars(const char* x) {
    while (*x != '\0') {
        // while (*x) {
        cout << *x++;
    }
    cout << endl;
}

// 第一种写法，最好的写法，必须传入数组大小size
void printValues(int* x, const size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// 第二种写法，必须传入数组大小size
void printValues_2(int x[], const size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// 第三种写法，最好不要用这种，形参的长度会引起误解，必须传入数组大小size
void printValues_3(int x[10], const size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// 第四种方法，数组的引用
// 必须加上小括号，int& x[10]表示10个int引用，int (&x)[10]表示指向含10个int的数组
// 数字10是必须要有的！数组的大小也必须是10个！
// 这种方法很不灵活，用得很少
void printValues_4(int (&x)[10]) {
    for (size_t i = 0; i != 10; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}

// x是一个指针，指向一个有很多行的数组的第一行，每一行都是一个包含10个int的数组，必须传入数组大小size
void printValue_5(int (*x)[10], int rowSize) {
    for (size_t i = 0; i != rowSize; ++i) {
        for (size_t j = 0; j != 10; ++j) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

// C++标准库的常用做法 —— 传两个指针，这种方法也比较常见
void printValue_6(const int* begin, const int* end) {
    while (begin != end) {
        cout << *begin++ << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
    printValue_6(arr, arr + 8);
    printValues(arr, 10);
    printValues_2(arr, 10);
    printValues_3(arr, 10);
    printValues_4(arr);

    int m[][10] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
                   {2, 4, 6, 8, 0, 1, 3, 5, 7, 9},
                   {1, 3, 5, 7, 9, 0, 2, 4, 6, 8}};
    printValue_5(m, 3);

    char s[] = "Hello World";
    printChars(s);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string st("Hello World");  // c风格字符串->string
    st += " bill";
    cout << "C++: " << st << endl;

    const char* str = st.c_str();
    cout << "C: " << str << endl;

    const size_t arr_size = 6;
    int int_arr[arr_size] = {0, 1, 2, 3, 4, 5};

    // 第一个元素【包括】 最后一个元素的下一位【不包括】
    vector<int> ivec(int_arr, int_arr + arr_size);  // 0,1,2,3,4,5
    for (vector<int>::const_iterator iter = ivec.begin(); iter != ivec.end();
         ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int> ivec2(int_arr + 1, int_arr + 4);  // 1,2,3
    for (vector<int>::const_iterator iter = ivec2.begin(); iter != ivec2.end();
         ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
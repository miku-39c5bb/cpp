#include <fstream>
#include <string>
#include "../include/get.h"

using namespace std;

int main() {
    // cout << "--------------测试--------------" << endl;

    // get(cin);

    // cout << "-----继续使用cin，输入一个double-----" << endl;
    // double dval;
    // cin >> dval;
    // cout << dval << endl;

    cout << "--------------新测试--------------" << endl;
    string file_name;
    cout << "Enter a file name: ";
    cin >> file_name;

    ifstream in_file(file_name.c_str());
    if (!in_file) {
        cerr << "error: can't open input file: " << file_name << endl;
        return -1;
    }
    get(in_file);

    return 0;
}
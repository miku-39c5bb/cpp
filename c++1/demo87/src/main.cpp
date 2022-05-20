#include <fstream>
#include <iostream>
#include <string>
#include "../include/get.h"

using namespace std;

ifstream& open_file(ifstream& in, const string& file_name) {
    in.close();  // 这个流可能已经被打开了，可以先关闭
    in.clear();  // 然后清除流的状态
    in.open(file_name.c_str());
    return in;
}

int main() {
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;

    ifstream in_file;
    // open_file(in_file, file_name);  // 这个函数比默认的打开文件的方式更安全
    if (!open_file(in_file, file_name)) {
        cerr << "error: can't open file: " << file_name << endl;
        return -1;
    }

    get(in_file);

    in_file.close();

    return 0;
}
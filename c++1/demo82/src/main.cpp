#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream outfile("test.txt");
    outfile << "Hello File!!" << endl;
    outfile.close();

    string file("one.txt");
    // ifstream infile(file.c_str());  // 传统的C++：以前必须用c风格字符串
    // ifstream infile(file);  // 现在可以用string
    ifstream infile;    // 流对象infile没有和一个文件绑定
    infile.open(file);  // 绑定
    // infile.open(file.c_str());
    if (!infile) {
        cout << "打开文件失败:" << file << endl;
        return -1;
    }

    string s;
    // 传统的C++：循环结束后，infile状态是eof
    // 现代C++不会这样
    while (infile >> s) {
        cout << s << endl;
    }
    infile.close();  // 关闭one.txt
    infile.clear();  // 恢复流状态

    file = "two";
    infile.open(file);
    if (!infile) {
        cout << "打开文件失败:" << file << endl;
        return -1;
    }
    while (infile >> s) {
        cout << s << endl;
    }
    infile.close();

    return 0;
}
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> files;
    files.push_back("one.txt");
    files.push_back("two.txt");
    files.push_back("none.txt");
    files.push_back("three.txt");

    string s;
    vector<string>::const_iterator iter = files.begin();
    while (iter != files.end()) {
        ifstream input(iter->c_str());
        if (!input) {
            cerr << "打开文件失败，检查文件 " << *iter << " 是否存在。" << endl;
            // break;
            input.clear();
            ++iter;
            continue;
        }

        while (input >> s) {
            cout << s << endl;
        }
        input.close();
        input.clear();
        ++iter;
    }

    system("pause");
    return 0;
}

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> svec;
    string str;
    cout << "Enter strings: (Ctrl+Z to end):" << endl;
    while (getline(cin, str)) {
        svec.push_back(str);
    }
    char** parr = new char*[svec.size()];
    size_t ix = 0;
    for (vector<string>::const_iterator iter = svec.begin(); iter != svec.end();
         ++iter, ++ix) {
        char* p = new char[(*iter).size() + 1];  // 需要申请空间
        strncpy(p, (*iter).c_str(), (*iter).size() + 1);
        parr[ix] = p;
    }

    cout << "Content of vector: " << endl;
    for (vector<string>::const_iterator iter = svec.begin(); iter != svec.end();
         ++iter) {
        cout << *iter << endl;
    }
    cout << "Content of character arrays: " << endl;
    for (ix = 0; ix != svec.size(); ++ix) {
        cout << *(parr + ix) << endl;
    }

    delete[] parr;
    return 0;
}
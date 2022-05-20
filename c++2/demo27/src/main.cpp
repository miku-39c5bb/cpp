// MSVC可以运行 cl
// g++不可以运行

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

class CCompareStringNoCase {
public:
    bool operator()(const string& str1, const string& str2) const {
        string str1LowerCase;
        str1LowerCase.resize(str1.size());
        transform(str1.begin(), str1.end(), str1LowerCase.begin(), tolower);

        string str2LowerCase;
        str2LowerCase.resize(str2.size());
        transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower);

        return str1LowerCase < str2LowerCase;
    }
};

int main() {
    set<string> xm;                           // 用到了默认的谓词（分大小写）
    set<string, CCompareStringNoCase> names;  // 用自己写的二元谓词，不分大小写
    names.insert("Tina");
    names.insert("jim");
    names.insert("Jack");
    names.insert("Sam");
    names.insert("hello");

    set<string, CCompareStringNoCase>::iterator iNameFound = names.find("SAM");
    if (iNameFound != names.end()) {
        cout << "找到了！" << *iNameFound << endl;
    } else {
        cout << "没找到！" << endl;
    }

    return 0;
}
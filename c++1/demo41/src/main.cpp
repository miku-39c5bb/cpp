#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string*> spvec;

    string str;
    cout << "Enter some strings(ctrl+z to end): " << endl;
    while (cin >> str) {
        string* pstr = new string;
        *pstr = str;
        spvec.push_back(pstr);
    }

    vector<string*>::const_iterator iter = spvec.begin();
    while (iter != spvec.end()) {
        cout << **iter << " " << (**iter).size() << endl;
        ++iter;
    }

    // 要记得释放内存
    iter = spvec.begin();
    while (iter != spvec.end()) {
        delete *iter;
        ++iter;
    }

    return 0;
}
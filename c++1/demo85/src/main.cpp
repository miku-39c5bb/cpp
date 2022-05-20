#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fileToVector(const string& file_name, vector<string>& svec);

int main() {
    vector<string> svec;
    string file_name, s;

    cout << "Enter file name:";
    cin >> file_name;
    switch (fileToVector(file_name, svec)) {
        case 1:
            cout << "error: 打开文件失败" << endl;
            break;
        case 2:
            cout << "error: system failure" << endl;
            break;
        case 3:
            cout << "error: read failure" << endl;
            break;
        case 4:
            cout << "eof" << endl;
            break;
    }

    for (vector<string>::const_iterator iter = svec.begin(); iter != svec.end();
         ++iter) {
        cout << *iter << endl;
    }

    // cout << "多少词" << svec.size() << endl;
    cout << "多少行" << svec.size() << endl;

    return 0;
}

int fileToVector(const string& file_name, vector<string>& svec) {
    ifstream in_file(file_name.c_str());
    if (!in_file) {
        cerr << "Error, can't open input file: " << file_name << endl;
        return 1;
    }

    string s;
    // while (in_file >> s) {
    //     svec.push_back(s);
    // }
    // in_file.close();
    while (getline(in_file, s)) {
        svec.push_back(s);
    }
    in_file.close();

    if (in_file.eof()) {
        return 4;  // 一切正常
    }
    if (in_file.bad()) {
        return 2;
    }
    if (in_file.fail()) {
        return 3;
    }
    return 0;
}
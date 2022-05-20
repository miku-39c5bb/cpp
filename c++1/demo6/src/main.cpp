#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> svec;

    cout << "Enter text(Ctrl+Z to end): " << endl;
    while (cin >> str) {
        svec.push_back(str);
    }
    if (svec.empty()) {
        cout << "No string?" << endl;
        return -1;
    }

    cout << "Transformed elements from the vector: " << endl;
    for (vector<string>::size_type i = 0; i != svec.size(); ++i) {
        for (vector<string>::size_type j = 0; j != svec[i].size(); ++j) {
            if (islower(svec[i][j])) {
                svec[i][j] = toupper(svec[i][j]);
            }
        }
        cout << svec[i] << "\t";
        if ((i + 1) % 8 == 0) {
            cout << endl;
        }
    }

    return 0;
}
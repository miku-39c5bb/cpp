#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    bool a = true;

    bool rain = true, getClass = false;
    if (rain || getClass) {
        cout << "Can't go out." << endl;
    }

    if (rain) {
        cout << "Go out." << endl;
    }
    if (!getClass) {
        cout << "上课" << endl;
    }

    string s("hello world");
    string::iterator it = s.begin();
    while (it != s.end() && !isspace(*it)) {
        *it++ = toupper(*it);
    }
    cout << s << endl;

    return 0;
}
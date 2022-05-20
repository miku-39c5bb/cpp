#include <iostream>
#include <vector>

using namespace std;

class Account {};
class Phone {};
class Name {};
class Record {
public:
    Account a;
    Phone b;
    Name c;
};

void lookup(const Account &account) {
    cout << "账号" << endl;
}
void lookup(const Phone &phone) {
    cout << "电话" << endl;
}
void lookup(const Name &name) {
    cout << "姓名" << endl;
}

void show(int x) {
    cout << x << endl;
}

void show(const vector<int> &v) {
    for (vector<int>::const_iterator iter = v.begin(); iter != v.end();
         ++iter) {
        cout << *iter << endl;
    }
}

class MyScreen {
public:
    void moveHome();
    void moveAbs(int, int);
    void moveRel(int, int, char *direction);
};

class YourScreen {
public:
    void move();
    void move(int, int);
    void move(int, int, char *direction);
};

int main() {
    MyScreen m;
    YourScreen n;

    Account x;
    Phone y;
    Name z;
    lookup(x);
    lookup(y);
    lookup(z);

    int a = 89;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);

    show(a);
    show(b);

    return 0;
}
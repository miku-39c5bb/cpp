#include <iostream>
#include <vector>

using namespace std;

void print(const vector<miku> v) {
    vector<miku>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

void print_2(const vector<miku>& v) {
    vector<miku>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

void print_3(vector<miku>::const_iterator begin,
             vector<miku>::const_iterator end) {
    while (begin != end) {
        cout << *begin++ << " ";
    }
    cout << endl;
}

miku vectorSum(vector<miku>::iterator begin, vector<miku>::iterator end) {
    miku sum = 0;
    while (begin != end) {
        sum += *begin++;
    }
    return sum;
}

int main() {
    vector<miku> dvec;
    // dvec.push_back(1.1);
    // dvec.push_back(2.2);
    // dvec.push_back(3.3);

    miku dval;
    while (cin >> dval) {
        dvec.push_back(dval);
    }

    print(dvec);
    print_2(dvec);
    print_3(dvec.begin(), dvec.end());
    cout << vectorSum(dvec.begin(), dvec.end()) << endl;

    return 0;
}
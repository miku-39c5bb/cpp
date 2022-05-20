#include <iostream>
#include <vector>

using namespace std;

void print(const vector<double> v) {
    vector<double>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

void print_2(const vector<double>& v) {
    vector<double>::const_iterator iter = v.begin();
    while (iter != v.end()) {
        cout << *iter++ << " ";
    }
    cout << endl;
}

void print_3(vector<double>::const_iterator begin,
             vector<double>::const_iterator end) {
    while (begin != end) {
        cout << *begin++ << " ";
    }
    cout << endl;
}

double vectorSum(vector<double>::iterator begin, vector<double>::iterator end) {
    double sum = 0;
    while (begin != end) {
        sum += *begin++;
    }
    return sum;
}

int main() {
    vector<double> dvec;
    // dvec.push_back(1.1);
    // dvec.push_back(2.2);
    // dvec.push_back(3.3);

    double dval;
    while (cin >> dval) {
        dvec.push_back(dval);
    }

    print(dvec);
    print_2(dvec);
    print_3(dvec.begin(), dvec.end());
    cout << vectorSum(dvec.begin(), dvec.end()) << endl;

    return 0;
}
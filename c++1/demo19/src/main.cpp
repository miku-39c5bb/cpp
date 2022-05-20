#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ia[] = {9, 2, 4, 6, 8};

    int* ip = ia;

    cout << *ia << endl;
    cout << *ip << endl;

    ip = &ia[1];
    cout << *ip << endl;

    int* ip2 = ia + 4;
    cout << *ip2 << endl;

    int* ip3 = ia + 10;
    cout << *ip3 << endl;

    cout << ip2 - ip << endl;
    cout << ip3 - ip << endl;
    cout << ip3 - ip2 << endl;

    ptrdiff_t n = ip2 - ip;
    cout << *ip << endl;
    cout << *ip2 << endl;
    cout << n << endl;

    int last = *(ia + 4);
    cout << "last: " << last << endl;
    cout << "last: " << *(ip + 3) << endl;
    cout << "last: " << *(ip + 4) << endl;

    int* p = &ia[2];
    cout << *p << endl;
    int j = p[1];
    cout << j << endl;
    cout << p[2] << endl;
    int k = p[-2];
    cout << k << endl;

    const size_t arr_size = 5;
    int arr[arr_size] = {1, 2, 3, 4, 5};
    int* p2 = arr;
    int* p3 = p2 + arr_size;
    cout << *p2 << endl;
    cout << *p3 << endl;

    for (int* ptr = p2; ptr != p3; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    const size_t size_sz = 5;
    int int_arr[size_sz] = {0, 1, 2, 3, 4};
    for (int *pbegin = int_arr, *pend = int_arr + size_sz; pbegin != pend;
         ++pbegin) {
        cout << *pbegin << endl;
    }

    vector<int> ivec;
    ivec.push_back(1);
    ivec.push_back(2);
    ivec.push_back(30);
    ivec.push_back(40);
    ivec.push_back(50);

    for (vector<int>::const_iterator iter = ivec.begin(); iter != ivec.end();
         ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
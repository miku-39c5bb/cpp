#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ival;
    vector<int> ivec;

    cout << "Enter numbers (Ctrl + Z to end): " << endl;
    while (cin >> ival) {
        ivec.push_back(ival);
    }

    if (ivec.empty()) {
        cout << "No element?" << endl;
        return -1;
    }

    cout << "Sum of each pair of counterpart elements in the vector: ";
    int left = 0, right = ivec.size() - 1;
    vector<int>::size_type cnt = 0;
    while (left < right) {
        cout << ivec[left++] + ivec[right--] << "\t";
        ++cnt;
        if (cnt % 6 == 0) {
            cout << endl;
        }
    }

    if (left == right) {
        cout << endl
             << "The center element isn't been summed, "
             << "and it's '" << ivec[left]
             << "'." << endl;
    }

    return 0;
}
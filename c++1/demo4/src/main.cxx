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

    cout << "Sum of each pair of adjacent elements in the vector: ";
    for (vector<int>::size_type i = 0; i < ivec.size() - 1; i += 2) {
        cout << ivec[i] + ivec[i + 1] << "\t";
    }
    if (ivec.size() % 2) {
        cout << endl
             << "The last element isn't been summed, "
             << "and it's '" << ivec[ivec.size() - 1]
             << "'." << endl;
    }

    return 0;
}
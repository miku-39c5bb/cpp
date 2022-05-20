#include "../head/demo.h"
#include <iostream>

using namespace std;

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int y[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 9; ++i)
    {
        cout << sum(x[i], y[i]) << " ";
    }
    cout << endl;

    cout << shortString("hello", "bill") << endl;
    cout << isShoter("www", ".com") << endl;

    return 0;
}
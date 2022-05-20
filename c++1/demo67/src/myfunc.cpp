#include "../head/myfunc.h"
#include <iostream>

using namespace std;

void print(int *arr, int size)
{
    for (int i = 0; i != size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int sum(int a, int b)
{
    return a + b;
}
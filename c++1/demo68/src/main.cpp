#include <iostream>

using namespace std;

int k = 0;

void do_a()
{
    static int m = 8;
    k++;
}

void do_b()
{
    int n = 99;
    k += 2;
}

size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    k += 9;
    do_a();
    do_b();
    cout << k << endl;
    cout << count_calls() << endl;
    cout << count_calls() << endl;
    cout << count_calls() << endl;

    return 0;
}
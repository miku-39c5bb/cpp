#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "We need three arguments" << endl;
        return -1;
    }

    cout << (atof(argv[1]) + atof(argv[2])) << endl;

    return 0;
}
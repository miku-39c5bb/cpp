#include <fstream>
#include <iostream>
#include <string>
#include "../include/get.h"

using namespace std;

ifstream &open_in_file(ifstream &in, string &file_name)
{
    in.close();
    in.clear();
    in.open(file_name.c_str());
    return in;
}

int main()
{
    string file_name;

    cout << "Enter the file name: ";
    cin >> file_name;

    ifstream ifs;
    if (!open_in_file(ifs, file_name))
    {
        cerr << "Can't open the file: " << file_name << endl;
    }

    get(ifs);

    ifs.close();

    return 0;
}
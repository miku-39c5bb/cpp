#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string fileName, s;
    vector<string> svec;

    fileName = "2.txt";

    ifstream inFile(fileName.c_str());
    if (!inFile)
        return -1;
    while (getline(inFile, s))
    {
        svec.push_back(s);
    }
    inFile.close();

    istringstream istrstream;
    string myWords;
    for (vector<string>::const_iterator iter = svec.begin(); iter != svec.end(); ++iter)
    {
        cout << *iter << endl;
        istrstream.str(*iter); // 放入输入字符串流
        while (getline(istrstream, myWords))
        {
            cout << myWords << endl;
        }
        istrstream.clear(); // 清除流的状态
    }

    return 0;
}
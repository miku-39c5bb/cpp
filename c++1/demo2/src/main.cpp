#include "..\head\Test.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);

    vector<int> v2(v1);
    // vector<string> v3(v1);

    vector<int> v4(10, -1);
    vector<int> v5(10); // 10个0

    vector<string> v6(10, "hi!");
    vector<string> v7(10); // 10个""

    Test test;
    test.showIntVec(v1);
    test.showIntVec(v2);
    test.showIntVec(v4);
    test.showIntVec(v5);
    test.showStringVec(v6);
    test.showStringVec(v7);

    v1[0] = 100;
    test.showIntVec(v1);
    v7[0] = "Hello!";
    test.showStringVec(v7);

    return 0;
}

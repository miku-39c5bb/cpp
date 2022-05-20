#ifndef __TEST_H
#define __TEST_H

#include <iostream>
#include <string>
#include <vector>

class Test {
private:
    /* data */
public:
    Test();
    ~Test();
    void showIntVec(std::vector<int> v);
    void showStringVec(std::vector<std::string> v);
};

Test::Test()
{
}

Test::~Test()
{
}

void Test::showIntVec(std::vector<int> v)
{
    for (std::vector<int>::size_type i = 0; i != v.size(); ++i) {
        std::cout << v[i] << "\t";
    }
    std::cout << std::endl;
}

void Test::showStringVec(std::vector<std::string> v)
{
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i) {
        std::cout << v[i] << "\t";
    }
    std::cout << std::endl;
}

#endif // !__TEST_H
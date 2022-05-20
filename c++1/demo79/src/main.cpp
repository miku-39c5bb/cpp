#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// using namespace std;

std::ofstream& print(std::ofstream& of) {
    std::cout << "test!" << std::endl;
    return of;
}

void foo(std::ostream& os) {
    std::cout << "test ostream" << std::endl;
}

int main() {
    foo(std::cout);
    std::ofstream ofs;
    foo(ofs);  // 向上转型
    std::ostringstream oss;
    foo(oss);

    std::cout << "Hello C++" << std::endl;

    std::fstream fs;
    std::stringstream ss;

    std::ofstream out1, out2;
    // out1 = out2;
    print(out1);

    std::vector<std::ofstream> vec;
    // vec.push_back(out1); // 错误，因为保存在容器里的对象必须可以复制
    // vec.push_back(out2);

    system("pause");
    return 0;
}
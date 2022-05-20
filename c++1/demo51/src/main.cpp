#include <iostream>
#include <stdexcept>

using namespace std;

class Student {
   public:
    Student(int age) {
        if (age < 0 || age > 120) {
            throw out_of_range("年龄不能小于0或大于120");
        }
        this->m_age = age;
    }

   private:
    int m_age;
};

int main() {
    try {
        Student zhangfei(-20);
        cout << "学生年龄正常" << endl;
    } catch (out_of_range err) {
        std::cerr << "学生年龄异常：" << err.what() << '\n';
    }

    return 0;
}
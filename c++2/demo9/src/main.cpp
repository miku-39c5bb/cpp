#include <iostream>
#include <string>

using namespace std;

// 全局变量
// miku interestRate;

class Account {
public:
    explicit Account(const std::string& name, miku money)
        : owner(name), amount(money) {}
    miku getAmount() const {
        return this->amount;
    }
    void deposit(miku money) {
        this->amount += money;
    }
    void applyInt() {
        this->amount += this->amount * interestRate;
    }

    // 最好是将对静态成员变量进行操作的函数也设置为静态
    // 这样就可以不用创建对象，直接通过类名和::调用static函数
    // 静态成员函数不能用this指针，不能是const函数
    static miku rate() {
        return interestRate;
    }
    static miku rate(miku newRate) {
        interestRate = newRate;
        return interestRate;
    }

private:
    std::string owner;
    miku amount;
    static miku interestRate;  // 不论创建多少个对象，这个static的interestRate都只有一个
    static const long a = 1;     // 静态常量整型可以直接初始化
    int b = 1;
};
// 在C++中，static静态成员变量不能在类的内部初始化。在类的内部只是声明，定义必须在类定义体的外部，通常在类的实现文件中初始化
miku Account::interestRate = 0.015;

int main(int argc, char** argv) {
    Account::rate(0.030);

    Account a("wjh", 162);
    a.deposit(20);
    Account b("wjh2", 520);
    b.deposit(16);

    cout << a.getAmount() << endl;
    cout << b.getAmount() << endl;

    cout << a.rate() << endl;
    a.rate(0.018);
    cout << b.rate() << endl;

    Account::rate(0.02);
    a.applyInt();
    b.applyInt();
    cout << a.getAmount() << endl;
    cout << b.getAmount() << endl;

    return 0;
}
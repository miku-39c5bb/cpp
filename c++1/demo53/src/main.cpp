#include <cassert>
#include <iostream>
// #define NDEBUG

using namespace std;

int money = 60000;

void get_money(int amount)
{
    if (amount < 0) {
        cout << "取钱数量必须不能小于0" << endl
             << "文件：" << __FILE__ << endl
             << "行：" << __LINE__ << endl
             << "日期：" << __DATE__ << endl
             << "时间：" << __TIME__ << endl;
        return;
    }
    money -= amount;
}

int add(int x, int y)
{
    return x * y;
}

int main()
{
#ifndef NDEBUG // 如果没有定义NDEBUG，则执行以下代码（调试）
    cout << "start main ..." << endl
         << endl;
#endif

    get_money(-1000);

    int result;
    result = add(1, 2);
    assert(result == 3); // 断言，用来调试
    // if (result != 3) {
    //     cout << "结果错了！" << endl;
    // }

#ifndef NDEBUG
    cout << endl
         << "end." << endl;
#endif

    return 0;
}
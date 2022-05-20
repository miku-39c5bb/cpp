#include <iostream>

using namespace std;

int main() {
    int sum = 0, value;
    
    // 这是一个不完善的方法
    // while(cin >> value)  // condition: !cin.good() 一次性检查了3个状态，bad/fail/eof
    // {
    //     sum += value;
    //     cout << "Sum is " << sum  << endl;
    // }

    // 更好的方法，注意：逗号表达式——结果取右边的值
    while(cin >> value, !cin.eof()) // condition: !cin.eof() 未到文件结尾
    {
        // cin.bad()，程序员无法再进行处理，抛出异常
        if(cin.bad())   
            throw std::runtime_error("IO stream corrupted");

        // cin.fail()，例如需要数字时却输入字符
        if(cin.fail())  
        {
            cerr << "bad data, try again" << endl;

            // 恢复流的正常状态，否则流就不能用了
            cin.clear();    

            // 清楚错误的数据，要么是200个字符，要么是碰到'\n'
            cin.ignore(200, '\n');  
            continue;
        }

        sum += value;
        cout << "Sum is " << sum << endl;
    }

    return 0;
}

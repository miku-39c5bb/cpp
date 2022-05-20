#include <iostream>

using namespace std;

void check_cin_state(istream& is);

int main() {
    cout << "检测cin的状态：" << endl;

    //           00010000  流的状态实际上是用二进制位表示 bad\fail\eof
    // cin.setstate(istream::badbit);       // 设置流的状态
    // cin.setstate(istream::failbit);
    // cin.setstate(istream::eofbit);
    // cin.setstate(istream::badbit | istream::failbit);
    // 同时设置流的多个状态
    cin.setstate(istream::failbit | istream::eofbit | istream::badbit);
    // 清除除了eof之外的其他状态，但是请注意：fail通常和bad或是eof绑定的
    cin.clear(istream::eofbit);
    cin.clear();  // 清除流的所有状态

    istream::iostate old_state = cin.rdstate();  // 将流的状态保存下来
    /*
    * 中间可以对流进行一些使用等操作
    */
    cin.clear(old_state);  // 还原流的状态

    check_cin_state(cin);

    cout << "请输入一个整数：" << endl;
    int n;
    cin >> n;
    cout << "再检查一次cin的状态" << endl;
    check_cin_state(cin);

    system("pause");
    return 0;
}

void check_cin_state(istream& is) {
    if (is.bad())
        cout << "cin bad()" << endl;
    else
        cout << "cin not bad()" << endl;

    if (is.fail())
        cout << "cin fail()" << endl;
    else
        cout << "cin not fail()" << endl;

    if (is.eof())
        cout << "cin eof()" << endl;
    else
        cout << "cin not eof()" << endl;

    if (is.good())
        cout << "is good()" << endl;
    else
        cout << "cin not good()" << endl;
}
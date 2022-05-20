#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    // cout 是流对象，ostream
    cout << "Hello!" << endl;

    // 文件输出流
    ofstream ofs("2.txt", ofstream::app);
    ofs << "hi, double" << endl;
    ofs << "hi, double" << endl;
    ofs.close();

    // 字符串输出流
    ostringstream oss;
    oss << "hello, wjh" << endl; // 输出到了内存
    oss << "wjh 520 double 20169" << endl;
    cout << oss.str() << endl; // 显示字符串流里面的字符串

    ostringstream format_message;
    format_message << "姓名： "
                   << "xxx" << endl
                   << "年龄： " << 17 << endl     // 17: int->string
                   << "体重： " << 107.8 << endl; // 107.8 double->string
    cout << format_message.str() << endl;

    string dump;
    string name;
    int age;
    double weight;

    istringstream input_str(format_message.str());
    input_str >> dump; // 扔掉
    input_str >> name;
    input_str >> dump;
    input_str >> age; // string->int
    input_str >> dump;
    input_str >> weight; // string->double
    cout << name << " " << age << " " << weight << endl;

    return 0;
}
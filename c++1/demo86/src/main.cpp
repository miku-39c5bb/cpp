#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    // ifstream ifs("file1.txt", ifstream::in);
    ifstream ifs("file1.txt");  // 使用默认的模式
    if (!ifs) {
        cerr << "can't open the file" << endl;
        return -1;
    }

    ifs >> s;
    ifs.close();
    cout << s << endl;

    // ofstream ofs("file2.txt", ofstream::out);
    ofstream ofs("file3.txt");
    ofs << "Hello, file3!" << endl;
    ofs.close();

    // 这三种写法是一样的，进行写操作时会将原来的清空
    // ofstream ofs4("file4");
    // ofstream ofs4("file4", ofstream::out);
    // ofstream ofs4("file4", ofstream::out | ofstream::trunc);

    // 将新的内容追加到原来内容的后面
    ofstream ofs4("file4", ofstream::out | ofstream::app);

    ofs4 << "Hello file4!" << endl;
    ofs4.close();

    // 这两个是一样的，这里的输出out不会将文件清空
    // fstream fs("file4");
    // fstream fs("file4", fstream::in | fstream::out);

    // trunc: 清空输入
    // fstream fs("file4", fstream::in | fstream::out | fstream::trunc);

    // 文件指针定位到最后
    fstream fs("file4", fstream::in | fstream::out | fstream::ate);

    // fs >> s;
    fs << "Test" << endl;
    fs.close();
    // cout << s;

    // 有些组合是没有意义的，比如trunc和in，这两个结合在一起，就先截断了，然后再in，这样就什么都读不到

    system("pause");
    return 0;
}
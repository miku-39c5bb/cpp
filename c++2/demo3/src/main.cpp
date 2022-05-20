#include <iostream>
#include <string>

using namespace std;

class Screen;  // 类声明

class LinkScreen {
    Screen* window;
    LinkScreen* next;
    LinkScreen* prev;
};

// 当两个类互相包含对方的时候（其中一个只能包含另一个的指针，另一个既可以包含指针，又可以包含对象），就必须有一个类要前置声明
class Y;  // 类的前置声明
class X {
private:
    // Y有声明，但没有定义
    Y* ptr;  // 前提：Y必须先声明，可以不忙定义
    // Y obj;  // 不行，Y必须先定义，然后才能创建Y的对象
};
class Y {
private:
    // X已经声明并定义了
    X* ptr;  // 可以用指针
    X obj;   // 也可以创建对象
};

class Record {  // 这是一个完整的类：类定义，类声明
private:
    typedef std::size_t size;

public:
    Record()
        : byte_count(0) {}
    Record(size s)
        : byte_count(s) {}
    Record(std::string s)
        : name(s), byte_count(0) {}

public:
    size get_count() const {
        return byte_count;
    }
    std::string get_name() const {
        return name;
    }

private:
    std::string name;
    size byte_count;
};

struct Person {
public:
    Person(const std::string& nm, const std::string& addr)
        : name(nm), address(addr) {}
    std::string get_name() const {
        return this->name;
    }
    std::string get_address() const {
        return this->address;
    }

private:
    std::string name;
    std::string address;
};

int main(int argc, char** argv) {
    cout << "hello" << endl;

    Screen* pScreen;

    Record r;         // 在堆栈上创建类的对象
    class Record r2;  // 这是c风格写法，等同于上一条语句

    Record* p = new Record;  // 在堆上动态地创建对象
    delete p;                // new对应delete

    // 不要使用未定义的类来声明对象
    // Screen screen;
    // 但是可以定义指向这个没有定义的类类型的指针
    Screen* pscreen;

    struct Person person("Bill", "花园街5号");
    cout << person.get_name() << ", " << person.get_address() << endl;

    return 0;
}
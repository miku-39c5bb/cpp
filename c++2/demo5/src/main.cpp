#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const std::string& name, const std::string& address)
        : name(name), address(address) {}
    std::string getName() const {
        return this->name;
    }
    std::string getAddress() const {
        return this->address;
    }

private:
    std::string name;
    std::string address;
};

class Screen {
public:
    typedef std::string::size_type index;
    Screen(index ht = 0, index wd = 0)
        : contents(ht * wd, 'a'), cursor(0), height(ht), width(wd),
          access_ctr(0) {}
    char get() const {
        return contents[cursor];
    }
    char get(index r, index c) {
        index row = r * width;
        return contents[row + c];
    }
    Screen& move(index, index);
    Screen& set(char);
    Screen& set(index, index, char);

    // const函数返回的类型也必须是const
    const Screen& display(std::ostream& os) const {
        ++access_ctr;
        do_display(os);
        return *this;
    }
    Screen& display(std::ostream& os) {
        ++access_ctr;
        do_display(os);
        return *this;
    }

private:
    std::string contents;
    index cursor;
    index height, width;

    // mutable 可变的，可以被const函数修改
    mutable size_t access_ctr;  // 计数器

    void do_display(std::ostream& os) const {
        os << this->contents;
    }
};

// move函数返回一个引用，这个引用可以继续调用它的成员函数
Screen& Screen::move(index r, index c) {
    index row = r * width;
    this->cursor = row + c;
    return *this;  // 返回当前对象的引用
}
Screen& Screen::set(char ch) {
    this->contents[cursor] = ch;
    return *this;
}
Screen& Screen::set(index r, index c, char ch) {
    int row = r * width;
    this->contents[row + c] = ch;
    return *this;
}

int main(int argc, char** argv) {
    // Person* me = new Person("wjh", "cyx dlx dzxlya");
    // cout << me->getName() << ", " << me->getAddress() << endl;
    Person me("wjh", "cyx dlx dzxlya");
    cout << me.getName() << ", " << me.getAddress() << endl;

    Screen myScreen(5, 3);
    cout << myScreen.get() << endl;
    myScreen.set(4, 2, 'b');
    cout << myScreen.get(4, 2) << endl;

    // myScreen.move(2, 3);
    // myScreen.set('d');
    // move函数返回一个引用，这个引用可以继续调用它的成员函数
    myScreen.move(2, 3).set('C').display(cout);
    cout << endl;
    myScreen.move(1, 1).set('W').move(1, 2).set('J').move(1, 3).set('H').display(cout).set(2, 1, '5').set(2, 2, '2').set(2, 3, '0');
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    myScreen.move(3, 1).set('X').move(3, 2).set('D').move(3, 3).set('D').display(cout);

    // myScreen.display(cout);

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Sales_item {
public:
    Sales_item(const std::string& in, unsigned units, double amount)
        : isbn(in), units_sold(units), revenue(amount) {}

    // 不对成员变量进行修改，所以加上const
    double avg_price() const {
        if (units_sold) {
            return revenue / units_sold;
        } else {
            return 0;
        }
    }

    bool same_isbn(const Sales_item& other) const {
        return this->isbn == other.isbn;
    }

    // 对成员变量进行了修改，所以不能加上const
    void add(const Sales_item& other) {
        this->units_sold += other.units_sold;
        this->revenue += other.revenue;
    }

private:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

class Person {
public:
    Person(const std::string& name, const std::string& address)
        : name(name), address(address) {}
    std::string getName() {
        return this->name;
    }
    std::string getAddress() {
        return this->address;
    }

private:
    std::string name;
    std::string address;
};

int main() {
    cout << "Hello class" << endl;

    Person a("wjh", "cyx dlx daxlya");
    cout << a.getName() << endl;
    cout << a.getAddress() << endl;

    cout << "----------------------------------------------------------------"
         << endl;

    Sales_item x(string("0-399-82477"), 2, 16.520);
    Sales_item y(string("0-399-82477"), 16, 16.520);

    cout << x.avg_price() << endl;

    if (x.same_isbn(y))
        x.add(y);

    cout << x.avg_price() << endl;

    return 0;
}
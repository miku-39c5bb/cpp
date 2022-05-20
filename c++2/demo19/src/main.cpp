#include <cstdlib>
#include <iostream>

using namespace std;

class Date {
public:
    Date(int y = 0, int d = 0, int m = 0)
        : month(m), day(d), year(y) {}

    int operator==(const Date& dt) const;
    int operator!=(const Date& dt) const;
    int operator<(const Date& dt) const;
    int operator<=(const Date& dt) const;
    int operator>(const Date& dt) const;
    int operator>=(const Date& dt) const;

private:
    int month, day, year;
};
int Date::operator==(const Date& dt) const {
    return (this->month == dt.month) &&
           (this->day == dt.day) &&
           (this->year == dt.day);
}
int Date::operator!=(const Date& dt) const {
    return !(*this == dt);  // [!=] <==> [!(=)]
}
int Date::operator<(const Date& dt) const {
    if (this->year == dt.year) {
        if (this->month == dt.month) {
            return this->day < dt.day;
        } else {
            return this->month < dt.month;
        }
    } else {
        return this->year < dt.year;
    }
}
int Date::operator<=(const Date& dt) const {
    return (*this < dt) || (*this == dt);  // [<=] <==> [< || ==]
}
int Date::operator>(const Date& dt) const {
    // return (*this != dt) && !(*this < dt);
    // return (*this != dt) && (*this >= dt);
    return !(*this <= dt);  // [>] <==> [!(<=)]
}
int Date::operator>=(const Date& dt) const {
    return !(*this < dt);  // [>=] <==> [!(<)]
}

int main(int argc, char** argv) {
    Date a(2016, 9, 1);
    Date b(2019, 6, 8);
    if (a < b) {
        cout << "a<b" << endl;
    }

    return 0;
}
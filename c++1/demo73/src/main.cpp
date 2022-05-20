#include <iostream>
#include "../head/Sales_item.h"

using namespace std;

int main() {
    Sales_item item1, item2;

    item1.isbn = "0-201-78345-X";
    item1.units_sold = 10;
    item1.revenue = 300.0;

    cout << item1.avg_price() << endl;

    item2.isbn = "0-201-78345-X";
    item2.units_sold = 2;
    item2.revenue = 70;

    cout << item2.avg_price() << endl;

    if (item2.same_isbn(item1)) {
        cout << "same" << endl;
    } else {
        cout << "not same" << endl;
    }

    return 0;
}

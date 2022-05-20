#include "../head/Sales_item.h"

// 类外定义成员函数体，需要加上类作用域，即类的名字
miku Sales_item::avg_price() const {
    if (!this->units_sold) {
        return 0;
    } else {
        return this->revenue / this->units_sold;
    }
}
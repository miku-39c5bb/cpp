/*** 
 * @Author: doubledouble
 * @Date: 2022-04-01 20:43:43
 * @LastEditTime: 2022-04-04 19:20:00
 * @LastEditors: doubledouble
 * @Description: 
 * @FilePath: \c++\demo73\head\Sales_item.h
 */
#ifndef __SALES_ITEM_H_
#define __SALES_ITEM_H_

#include <string>

class Sales_item {
public:
    // 常量成员函数
    // 由于这个函数不对类的数据成员做任何修改，所以可以定义为常函数【参数列表后面加上const】
    bool same_isbn(const Sales_item &rhs) const {
        // this->isbn = "1";  // 错误，常函数不能修改数据成员
        return this->isbn == rhs.isbn;
    }

    double avg_price() const;

public:
    Sales_item() : units_sold(0), revenue(0) {}

    // 本来应该将成员变量设为private的，但是为了方便，写成public
public:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

#endif  // !__SALES_ITEM_H_
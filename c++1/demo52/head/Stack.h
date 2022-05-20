#ifndef __STACK_H_
#define __STACK_H_

#include <deque>
#include <exception>

template <class T>
class Stack {
protected:
    std::deque<T> c;

public:
    class ReadEmptyStack : public std::exception { // 自己写了一个异常对象 ReadEmptyStack，该对象继承了 std::exception 对象
    public:
        virtual const char* what() const throw() // 重写了std::excption 对象的 what() 方法
        {
            return "read empty stack 堆栈是空的";
        }
    };

    bool empty() const
    {
        return c.empty();
    }

    void push(const T& elem)
    {
        c.push_back(elem);
    }

    T pop()
    {
        if (c.empty()) {
            throw ReadEmptyStack(); // 如果栈空，抛出类对象异常ReadEmptyStack()
        }
        T elem(c.back());
        c.pop_back();
        return elem;
    }

    T& top()
    {
        if (c.empty()) { // 如果栈空，抛出类对象异常ReadEmptyStack()
            throw ReadEmptyStack();
        }
        return c.back();
    }
};

#endif // !__STACK_H_
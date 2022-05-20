#include <iostream>

class Date {
};

void process() { }

bool is_present(int* x, int y);

Date& calendar(const char* s);

int power(int x, int y)
{
    y--;
    int result = x;
    while (y--) {
        result *= x;
    }
    return result;
}

int abs(int x)
{
    return x >= 0 ? x : -x;
}

// 最大公约数
int gcd(int v1, int v2)
{
    while (v2) {
        int temp = v2;
        v2 = v1 % v2;
        v1 = temp;
    }
    return v1;
}

int main()
{
    std::cout << gcd(15, 123) << std::endl;

    std::cout << abs(0) << std::endl;
    std::cout << abs(1) << std::endl;
    std::cout << abs(-1) << std::endl;

    std::cout << power(2, 1) << std::endl;
    std::cout << power(2, 4) << std::endl;
    std::cout << power(2, 6) << std::endl;
    std::cout << power(2, 8) << std::endl;
    std::cout << power(2, 20) << std::endl;

    return 0;
}
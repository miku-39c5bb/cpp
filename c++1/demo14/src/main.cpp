/*
 * 标准库bitset应用实例 - 埃拉托斯特尼“筛法”
 *
 * “筛法”，用来查找质数，早在两千多年前就被希腊数学家埃拉托斯特尼(Eratosthenes)发现了
 *
 * 先把N个自然数按次序排列起来
 * 1不是质数，也不是合数，要划去
 * 第二个数2是质数留下来，而把2后面所有能被2整除的数都划去
 * 2后面第一个没划去的数是3，把3留下，再把3后面所有能被3整除的数都划去
 * 3后面第一个没划去的数是5，把5留下，再把5后面所有能被5整除的数都划去
 * 这样一直做下去，就会把不超过N的全部合数都筛掉，留下的就是不超过N的全部质数
 *
 * 因为希腊人是把数写在涂腊的板上，每要划去一个数，就在上面记以小点，
 * 寻求质数的工作完毕后，这许多小点就像一个筛子，
 * 所以就形象地把埃拉托斯特尼的方法叫做“埃拉托斯特尼筛”，简称“筛法”
 */

#include <bitset>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int const max_number(100);
    const int max_test((int)sqrt((double)max_number));
    bitset<max_number + 1> numbers;
    numbers.set();
    numbers[1] = 0;
    for (int i(1); i != max_test; ++i) {
        if (numbers[i]) {
            for (int j(i * i); j < max_number + 1; j += i) {
                numbers[j] = 0;
            }
        }
    }
    cout << numbers << endl;
    cout << "The number of primes less than " << max_number + 1 << " is "
         << numbers.count() << ".\n\n";
    for (int i = 1; i != max_number + 1; ++i) {
        if (numbers[i]) {
            cout << i << ", ";
        }
    }
    cout << endl;

    return 0;
}
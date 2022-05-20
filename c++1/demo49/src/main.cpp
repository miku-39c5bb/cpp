#include <iostream>
#include <new>

using namespace std;

class Dog {
public:
    Dog()
    {
        parr = new int[1000000]; // 4MB
    }

private:
    int* parr;
};

int main()
{
    Dog* pDog;
    try {
        for (size_t i = 1; i <= 1000; ++i) {
            pDog = new Dog();
            cout << i << ": new Dog success!" << endl;
        }
    } catch (bad_alloc err) {
        cout << "new Dog fail: " << err.what() << endl;
    }

    return 0;
}
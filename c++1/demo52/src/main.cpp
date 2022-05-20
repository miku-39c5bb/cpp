#include "../head/Stack.h"
#include <iostream>

using namespace std;

int main()
{
    try {
        Stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        cout << "pop: " << st.pop() << endl;
        cout << "top: " << st.top() << endl;
        cout << "pop: " << st.pop() << endl;
        cout << "pop: " << st.pop() << endl;
        cout << "top: " << st.top() << endl;
        cout << "pop: " << st.pop() << endl;
    } catch (const exception& err) {
        cerr << "发生异常：" << err.what() << endl;
    }

    return 0;
}
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1("hello");

    // "hello" c风格字符串——字面值常量——常量字符数组
    char s2[] = "hello";  // 拷贝
    const char* cp =
        "hello";  // const char* 指向常量字符数组"hello"【有一个隐藏的'\0'】
    while (*cp) {
        cout << *cp++;
    }
    cout << endl;

    char ca1[] = {'C', '+', '+'};  // 缺少'\0'，不是c风格字符串
    char ca2[] = {'C', '+', '+', '\0'};
    char ca3[] = "C++";

    char* p1 = ca1;
    cout << p1 << endl;

    printf("Hello C!\n");
    cout << "Hello C++" << endl;

    const char* cp1 = "A string example";    // 16+1
    const char* cp2 = "A different string";  // 18+1
    // char cp1[] = "A string example";    // 16+1
    // char cp2[] = "A different string";  // 18+1
    cout << strlen(cp1) << endl;
    cout << strlen(cp2) << endl;

    string str1("A string example");
    string str2("A different string");
    cout << str1.size() << endl;
    cout << str2.size() << endl;

    char ca[] = {'C', '+', '+'};
    cout << ca << endl;
    cout << strlen(ca) << endl;

    str1 = "Bill";
    str2 = "Mary";
    cp1 = "Bill";
    cp2 = "Mary";

    string largeS;
    largeS = str1;
    cout << "largeS: " << largeS << endl;
    largeS += " " + str2;
    cout << "largeS: " << largeS << endl;

    str1 = str2;  // 复制（拷贝）
    // cp1 = cp2;    // cp1指向cp2指向的"Mary"

    char largeStr[10] = {0};  // 全部初始化为0 '\0'
    strncpy(largeStr, cp1, 4);
    strncat(largeStr, " ", 1);
    strncat(largeStr, cp2, 4);
    cout << "largeStr: " << largeStr << endl;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << cp1 << endl;
    cout << cp2 << endl;
    if (str1 < str2) {
        cout << "str1 < str2" << endl;
    } else if (str1 > str2) {
        cout << "str1 > str2" << endl;
    } else {
        cout << "str1 == str2" << endl;
    }

    if (strcmp(cp1, cp2) > 0) {
        printf("cp1 > cp2\n");
    } else if (strcmp(cp1, cp2) < 0) {
        printf("cp1 < cp2\n");
    } else {
        printf("cp1 == cp2\n");
    }

    return 0;
}
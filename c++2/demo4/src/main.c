#include <stdio.h>
#include <string.h>

struct Person {
    // void getName() const {}  // c的struct里面不能定义函数
    char name[30];
    char address[100];
};

int main(int argc, char** argv) {
    struct Person p;
    strcpy(p.name, "Bill");
    strcpy(p.address, "花园街5号");

    printf("%s, %s\n", p.name, p.address);
    printf("hello C!\n");

    return 0;
}
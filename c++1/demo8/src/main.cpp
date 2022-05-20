#include <stdio.h>

int main()
{
    int a;

    a = 12;
    printf("%d\n", a);

    a = 0x12;
    printf("%d\n", a);

    a = 012;
    printf("%d\n", a);

    return 0;
}
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("\t\t----------Signed----------\n");

    printf("char: %d %d\n", (int) SCHAR_MAX, (int) SCHAR_MIN);
    printf("short: %d %d\n", (int) SHRT_MAX, (int) SHRT_MIN);
    printf("int: %d %d\n", INT_MAX, INT_MIN);
    printf("long: %ld %ld\n\n", LONG_MAX, LONG_MIN);

    printf("\t\t----------Unsigned--------\n");
    
    printf("unsigned char: %d %d\n", (int) UCHAR_MAX, 0);
    printf("unsigned short: %d %d\n", (int) USHRT_MAX, 0);
    printf("unsigned int: %lu %d\n", UINT_MAX, 0);
    printf("unsigned long: %lu %ld\n", ULONG_MAX, 0);



    return 0;
}
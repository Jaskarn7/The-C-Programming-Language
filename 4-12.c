#include <stdio.h>

#define NUMBER 19234 // Number to be converted to string
#define NUMBERSIZE 15

void itoa(int n, char s[])
{
    static int p = 0; // Used to insert into array s
    if (n / 10)
        itoa((n / 10), s);
    s[p++] = n % 10 + '0';
    s[p] = '\0';
}

void print_arr(char s[])
{
    for (int i=0; s[i]!='\0'; ++i)
        printf("%c ", s[i]);
    printf("\n");
}

int main(void)
{
    char s[NUMBERSIZE];
    itoa(NUMBER, s);
    print_arr(s);
    return 0;
}

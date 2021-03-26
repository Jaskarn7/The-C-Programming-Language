#include <stdio.h>
#define LIM 1000

void print_arr(int s[]) 
{
    int i=0;
    while (s[i] != '\0')
        putchar(s[i++]);
    printf("\n");
}

int main(void) 
{
    int s[LIM];
    int c;
    int i = 0;
    while (i < LIM-1) {
        c = getchar();
        if (c == '\n') break;
        else if (c == EOF) break;
        s[i++] = c;
    }
    s[i] = '\0';
    print_arr(s);
    return 0;
}
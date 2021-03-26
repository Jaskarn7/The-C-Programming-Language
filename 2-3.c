#include <stdio.h>

#define LIMIT 10

int power_16(int p) 
{
    int result = 1;
    while (p-- > 0) result *= 16;
    return result;
}

int htoi(char s[]) 
{
    int i = 0;
    while (s[++i] != '\0') ;
    int p = 0, result = 0;
    while (--i >= 0) 
        result += (power_16(p++) * (s[i] - '0'));
    return result;
}

int main(void)
{
    int c, i = 0;
    char s[LIMIT];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            s[i] = '\0';
            printf("%d\n", htoi(s));
            i = 0;
        }
        else {
            s[i++] = c;
        }
    }
}
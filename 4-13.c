#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[])
{
    if (s[0] != '\0')
        reverse(s + 1);
    if (s[0] != '\0')
        printf("%c", s[0]);
}

int get_line(char s[])
{
    int c, i = 0;
    while ((c = getchar()) != '\n' && i < MAXLINE)
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main(void)
{
    char s[MAXLINE];
    while (get_line(s) > 0) {
        reverse(s);
        printf("\n");
    }
    return 0;
}

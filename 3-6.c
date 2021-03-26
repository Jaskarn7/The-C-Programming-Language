#include <stdio.h>

#define MAXLINE 100

void swap(char s[], int l, int h)
{
    char temp = s[l];
    s[l] = s[h];
    s[h] = temp;
}

void reverse(char s[], int l)
{
    int higher = l-1, lower = 0;
    while (lower <= higher) 
        swap(s, lower++, higher--);
}

void itoa(int n, char s[], int w) 
{
    int  i = 0;
    do {
        s[i++] = n % 10 +'0';
    } while ((n /= 10) > 0);
    while (i < w)
        s[i++] = ' ';
    reverse(s, i);
    s[i] = '\0';
}

void print_arr(char s[])
{
    int i = 0;
    while (s[i] != '\0') 
        printf("%c", s[i++]);
    printf("\n");
}

int main(void)
{
    int n, w;
    char s[MAXLINE];
    scanf("%d %d", &n, &w);
    itoa(n, s, w);
    print_arr(s);
    return 0;
}
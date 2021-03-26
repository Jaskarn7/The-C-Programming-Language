#include <stdio.h>

#define MAXLINE 1000

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

char conv_to_char(int n)
{
    char c = n + '0';
    if (c > '9') 
        c += 'A' - '9' - 1;
    return c;
}

void itob(int n, char s[], int b)
{
    int i = 0;
	do {
        s[i++] = conv_to_char(n % b);
    } while ((n /= b) > 0);
    reverse(s, i);
    s[i] = '\0';
}

int main(void)
{
	char s[MAXLINE];
	int n, b;
    scanf("%d %d", &n, &b);
	itob(n, s, b);
	int i = 0;
	while (s[i] != '\0') 
        printf("%c ", s[i++]);
	return 0;
}
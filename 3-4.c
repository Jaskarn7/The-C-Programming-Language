#include <stdio.h>

void reverse_str(char s[], int n)
{
    int l = 0, h = n - 1;
    char temp;

    while (l < h) {
        temp = s[l];
        s[l++] = s[h];
        s[h--] = temp;
    }
}

void itoa(int n, char s[])
{
    int ptr_s = 0;
    char neg_sign = 0;
    
    if (n < 0) {
        neg_sign = 1;
        n *= -1;
    }

    do {
        s[ptr_s++] = n % 10 + '0';
    } while ((n /= 10) > 0) ;

    if (neg_sign)
        s[ptr_s++] = '-';
    s[ptr_s] = '\0';

    reverse_str(s, ptr_s);
}

int main(void)
{
    int n = 949030918;
    char s[10];
    itoa(n, s);
    printf("Result: %s\n", s);
    return 0;
}
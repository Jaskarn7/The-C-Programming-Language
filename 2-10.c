#include <stdio.h>

void lower(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i)
        s[i] -= (s[i] >= 'a' && s[i] <= 'z') ? 32 : 0;
}

int main(void)
{
    char s[] = "Hello, woRld!";
    lower(s);
    printf("%s\n", s);
    return 0;
}
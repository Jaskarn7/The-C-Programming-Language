#include <stdio.h>

#define MAXLINE 1000

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; ++i)
        for (int j = 0; s2[j] != '\0'; ++j) 
            if (s2[j] == s1[i]) return i;
    return -1;
}

int main(void) 
{
    char s1[MAXLINE], s2[MAXLINE];
    int c, i = 0;
    while ((c = getchar()) != '\n') 
        s1[i++] = c;
    s1[i] = '\0';
    i = 0;
    while ((c = getchar()) != '\n')
        s2[i++] = c;
    s2[i] = '\0';
    printf("%d\n", any(s1, s2));
    return 0;
}
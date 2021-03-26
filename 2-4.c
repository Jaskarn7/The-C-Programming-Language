#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[])
{
    for (int a = 0; s2[a] != '\0'; ++a) {
        int i, j;
        for (i = j = 0; s1[i] != '\0'; ++i) {
            if (s1[i] != s2[a]) 
                s1[j++] = s1[i];
        }
        s1[j] = '\0';
    }
}

void print_string(char s[])
{
    int i = 0;
    while (s[i] != '\0') printf("%c", s[i++]);
    printf("\n");
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
    squeeze(s1, s2);
    print_string(s1);
    return 0;
}
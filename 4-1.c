#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[])
{
    int c, i = 0;
    while ((c = getchar()) != '\n' && i < MAXLINE)
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int str_index(char s[], int ll, char pattern[])
{
    int i, j, k;
    for (i = ll-1; i >= 0; --i) {
        for (j = i, k = 0; pattern[k] != '\0' && s[j] != '\0' && s[j] == pattern[k]; ++j, ++k) ;
        if (k > 0 && pattern[k] == '\0') return i;
    }
    return -1;
}

int main(void)
{
    char s[MAXLINE];
    int ll; // Line length
    char pattern[MAXLINE];
    printf("First Enter the pattern then lines: \n");
    get_line(pattern);
    while ((ll = get_line(s)) > 0) {
        int pos = str_index(s, ll, pattern);
        printf("%d\n", pos);
    }
    return 0;
}

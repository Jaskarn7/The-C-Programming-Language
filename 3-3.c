#include <stdio.h>

int is_alnum(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

void expand(char s[], char p[])
{
    int ptr_s = 0;
    int ptr_p = 0;

    while (s[ptr_s] != '\0') {
        if (is_alnum(s[ptr_s]) && s[ptr_s + 1] == '-') {
            for (int i = s[ptr_s]; i <= s[ptr_s + 2]; ++i)
                p[ptr_p++] = i; 
            ptr_s += 2;
            continue;
        }
        ++ptr_s;
    }
    p[ptr_p] = '\0';
}

int main(void)
{
    char s[] = "-a-z0-9";
    char p[100];
    expand(s, p);
    printf("Result: %s\n", p);
    return 0;
}
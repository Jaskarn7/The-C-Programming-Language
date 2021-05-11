#include <stdio.h>

#define MAXWORD 1000

void escape(char s[], char t[])
{
    for (int i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n': 
        }
    }
}

int main(void)
{
    int c;
    char t[MAXWORD];
    char s[MAXWORD];

    int cntr = 0;
    
    while ((c = getchar()) != EOF && cntr < MAXWORD - 1) 
        t[cntr++] = c;
    t[cntr] = '\0'

    escape(s, t);
}
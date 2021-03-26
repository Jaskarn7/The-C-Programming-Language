#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
static char buffer;
int bufsize = 0;


struct key {
    char *word;
    int count;
} keytab[] = {
    "elliot", 0,
    "farleen", 0,
    "hello", 0,
    "jaskarn", 0
};

int NKEYS = (sizeof(keytab) / sizeof(keytab[0]));

char get_ch()
{

    if (bufsize == 0)
        return getchar();
    --bufsize;
    return buffer;
}

void unget_ch(char w)
{
    buffer = w;
    bufsize = 1;
}

int get_word(char *word)
{
    int c;
    char *p = word;
    while (isspace(c = get_ch()));
    if (c != EOF)
        *p++ = c;
    if (!isalpha(c)) {
        *p = '\0';
        return c;
    }
    for (int nwords = 0; nwords < MAXWORD; ++nwords, p++) {
        if (!isalnum(*p = get_ch())) {
            unget_ch(*p);
            break;
        }
    }
    *p = '\0';
    return word[0];
}

int binary_search(char *word)
{
    int low = 0, high = NKEYS - 1;
    int mid, cond;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, keytab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main(void)
{
    char word[MAXWORD];
    int n;
    while (get_word(word) != EOF)
        if (isalpha(word[0]))
            if ((n = binary_search(word)) >= 0)
                keytab[n].count++;
    for (int i=0; i < NKEYS; ++i)
        printf("%s: %d\n", keytab[i].word, keytab[i].count);
    return 0;
}

#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, w = 0;

    char state = OUT;

    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\t' || c == '\n') && state == IN)
            state = OUT;
        else if (state == OUT) {
            state = IN;    
            ++w;
        }
    }

    printf("\nWords: %d\n", w);

    return 0;
}

/**
 * Testing input:
 *          hello   world
 *    jakdsljfk     kjdlsj;aadfslk;jflskdjfs
 * kasjdflkjs k k   l           ieroqncjxj
 * kajsl                    
 * ^Z
 * 
 * Result -> Words: 10
*/
#include <stdio.h>

int main(void)
{
    int l = 0, ll = 0, nc = 0, c = 0;
    // l - lines, ll - line length, nc - new character
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            printf("Length of the line is: %d\n", ll);
            ++l;
            ll = 0;
        }
        else {
            ++ll;
        }
    }
    printf("Total characters: %d, total lines: %d\n", nc, l);
    return 0;
}
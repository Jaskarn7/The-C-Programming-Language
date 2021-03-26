#include <stdio.h>

#define MAXLINES 5000
#define MAXLEN 100

int get_line(char *p)
{
    char *temp = p;
    int len = 0, c;
    while ((c = getchar()) != '\n' && len < MAXLEN) {
        ++len;
        *temp++ = c;
    }
    *temp = '\0';
    return len;
}

int read_lines(char *line_ptr[])
{
    int len, n_lines = 0;
    char *p;
    while ((len = get_line(p)) > 0) {
        if (n_lines > MAXLINES)
            return -1;
        line_ptr[n_lines++] = p;
    }
    return n_lines;
}

int main(void)
{
    char *line_ptr[MAXLEN];
    int n_line = read_lines(line_ptr);
    printf("Number of lines: %d\n", n_line);
    return 0;
}

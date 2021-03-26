#include <stdio.h>
#include <stdlib.h>

#define MAXWORD 100

void get_reqd_line(FILE *fp1, FILE *fp2, char *l1, char *l2)
{
    int a, b;
    char *p1 = l1;
    char *p2 = l2;

    while ((a = getc(fp1)) != EOF && (b = getc(fp2)) != EOF) {
        if (a == '\n' || b == '\n') {
            if (a != b) {
                if (a != '\n')
                    while ((a = getc(fp1)) != '\n')
                        *p1++ = a;
                else
                    while ((b = getc(fp2)) != '\n')
                        *p2++ = b;
                *p1 = '\0';
                *p2 = '\0';
                return;
            }
            else {
                p1 = l1;
                p2 = l2;
            }
            continue;
        }

        *p1++ = a;
        *p2++ = b;

        if (a != b) {
            while ((a = getc(fp1)) != '\n')
                *p1++ = a;
            while ((b = getc(fp2)) != '\n')
                *p2++ = b;
            *p1 = '\0';
            *p2 = '\0';
            return;
        }
    }
    *l1 = '\0';
    *l2 = '\0';
}

int main(int argc, char *argv[])
{
    char *file1;
    char *file2;

    if (argc != 3) {
        printf("Usage ./<Program Name> <File Name> <File Name>\n");
        return 0;
    }
    else {
        file1 = argv[1];
        file2 = argv[2];
    }

    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");
    char *l1 = (char *) malloc(MAXWORD + 1);
    char *l2 = (char *) malloc(MAXWORD + 1); /* Stores the line from the files */

    get_reqd_line(fp1, fp2, l1, l2);

    printf("%s\n%s\n", l1, l2);

    fclose(fp1);
    fclose(fp2);
}

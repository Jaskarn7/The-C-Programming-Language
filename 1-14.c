#include <stdio.h>

int main(void)
{
    int arr[255];
    int checker[255];
    for (int i = 0; i < 255; ++i) {
        arr[i] = 0;
        checker[i] = 0;
    }

    unsigned int c;
    while ((c = getchar()) != EOF) 
        if (c != ' ' && c != '\n' && c != '\t') {
            ++arr[c];
            checker[c] = 1;
        }

    int max_in_arr = 0;
    for (int i = 0; i < 255; ++i)
        if (arr[i] > max_in_arr)
            max_in_arr = arr[i];
    
    /* Print the histogram */
    while (max_in_arr > 0) {
        for (int i = 0; i < 255; ++i) 
            if (arr[i] == max_in_arr) {
                printf("*");
                --arr[i];
            }
            else
                printf(" ");
        printf("\n");
        --max_in_arr;
    }

    for (unsigned int i = 0; i < 255; ++i)
        if (checker[i])
            printf("%c", (char) i);
        else
            printf(" ");
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define MAXCHARACTERS 1000
#define IN 1
#define OUT 0

int main(void) 
{
    int c, length = 0, i;
    int arr[MAXCHARACTERS];
    int state = OUT;
    for (i=0; i < MAXCHARACTERS; i += 1) arr[i] = 0;
    i = 0;

    // Takes the input
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            if (length > 0) {
                arr[i] = length;
                ++i;
            }
            length = 0;
        }
        else state = IN;
        if (state == IN) ++length;
    }
    // Get the maximum length word from array
    int max_word_length = INT_MIN;
    int n = sizeof(arr)/sizeof(arr[0]); 
    for (i = 0; i < n; i += 1) if (arr[i] > max_word_length) max_word_length = arr[i];
    
    // Printing the histogram starts from here
    while (max_word_length) {
        for (i = 0; i < n; i += 1) {
            if (arr[i] > 0 && arr[i] == max_word_length) {
                printf("*");
                --arr[i];
            }
            else if (arr[i] > 0) printf(" ");
        }
        printf("\n");
        --max_word_length;
    }
    return 0;
}
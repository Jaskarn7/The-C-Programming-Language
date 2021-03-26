#include <stdio.h>

#define MAXLINES 1000

int get_line(int arr[]) 
{
    int c, length = 0;
    for (int i=0; i < MAXLINES && (c = getchar()) != EOF &&  c != '\n'; ++i) {
        arr[i] = c;
        ++length;
    }
    return length;
}

void printline(int arr[], int ll)
{
    for (int i=0; i<ll; ++i) 
        putchar(arr[i]);
}

int main(void)
{
    int ll; // line length
    int arr[MAXLINES];
    while ((ll = get_line(arr)) > 0) {
        if (ll > 80) 
            printline(arr, ll);
            printf("Length was: %d\n", ll);
    }
    return 0;
}

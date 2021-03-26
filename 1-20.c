#include <stdio.h>

#define TABSTOP 4
#define MAXLINES 1000

int detab(int arr[], int ll) 
{
    if (ll % TABSTOP == 0) {
        arr[ll] = ' ';
        ++ll;
    }
    while ((ll % TABSTOP) != 0) {
        arr[ll] = ' ';
        ++ll;
    }
    return ll;
}

int get_line(int arr[])
{
    int c, ll = 0;
    while ((c = getchar()) != '\n') {
        if (c == '\t') {
            ll = detab(arr, ll);
        }
        else {
            arr[ll] = c;
            ++ll;
        }
    }
    arr[ll] = '\0';
    return ll;
}

void print_arr(int arr[], int ll) 
{
    for (int i = 0; arr[i] != '\0'; ++i)
        putchar(arr[i]);
    printf("\n");
}

int main(void)
{
    int ll;
    int arr[MAXLINES];
    while ((ll = get_line(arr)) > 0) {
        print_arr(arr, ll);
    }
    return 0;
}
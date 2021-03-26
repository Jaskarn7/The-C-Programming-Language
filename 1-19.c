#include <stdio.h>

#define MAXLINES 1000

int get_line(int arr[]) 
{
    int c, i = 0, ll = 0;
    while ((c = getchar()) != '\n' && i < MAXLINES) {
        arr[i] = c;
        ++i;
        ++ll;
    }
    return ll;
}

void swap(int arr[], int l, int h)
{
    int temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
}

void reverse(int arr[], int ll) 
{
    int lower = 0, higher = ll-1;
    while (lower <= higher) {
        swap(arr, lower, higher);
        ++lower;
        --higher;
    }
}

void print_arr(int arr[], int ll) 
{
    for (int i = 0; i < ll; i++)
        putchar(arr[i]);
    printf("\n");
}

int main(void) 
{
    int ll;
    int arr[MAXLINES];
    while ((ll = get_line(arr)) > 0) {
        reverse(arr, ll);
        print_arr(arr, ll);
    }
    return 0;
}
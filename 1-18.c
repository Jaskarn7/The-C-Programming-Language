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

void print_arr(int arr[], int ll) 
{
    for (int i=0; i<ll; ++i) putchar(arr[i]);
    printf("\n");
}

int remove_from_front(int arr[], int ll) 
{
    int p = 0;
    while ((arr[p] == ' ' || arr[p] == '\t') && p < ll)
        ++p;
    int temp = p;
    int i = 0;
    while (p < ll) {
        arr[i] = arr[p];
        ++p;
        ++i;
    }
    return ll-temp;
}

int remove_from_arr(int arr[], int ll) 
{
    ll = remove_from_front(arr, ll);
    return ll;
}

int main(void) 
{
    int ll;
    int arr[MAXLINES];
    while ((ll = get_line(arr)) > 0) {
        ll = remove_from_arr(arr, ll);
        print_arr(arr, ll);
    }
    return 0;
}
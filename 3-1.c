#include <stdio.h>

/**
 * @param arr, Array in which binary search is to be implemented
 * @param n, Size of Array (arr)
 * @param k, Element to be searched in Array (arr)
 * @return index of k in arr if found otherwise -1
*/
int binsearch(int arr[], int n, int k) 
{
    int l, h, mid;
    l = 0;
    h = n - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (k < arr[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    if (k == arr[l - 1])
        return l - 1;
     
    return -1;
}

int main(void)
{
    int arr[] = {1, 4, 5, 8, 12, 104};
    printf("%d\n", binsearch(arr, sizeof(arr)/sizeof(arr[0]), 4));
    return 0;
}
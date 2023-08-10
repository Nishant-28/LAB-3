// Write a program to implement Binary Search to give the position of
// leftmost appearance of the element in the array being searched. Display the number of
// comparisons made while searching.
// Input:
// Enter size of array: 10
// Enter elements of the array: 2 3 7 7 7 11 12 12 20 50
// Enter the key to be searched: 7
// Output:
// 7 found at index position 2
// Number of comparisons: 3


#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    int comp = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        comp++;
        if (arr[m] == x)
        {
            if (m == 0 || arr[m - 1] != x)
                return m;
            else
                r = m - 1;
        }
        else if (arr[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    int n, x;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        printf("Element not found");
    else
        printf("%d found at index %d\n", x, result);

    printf("Number of comparisons: %d", result + 1);

    return 0;
}

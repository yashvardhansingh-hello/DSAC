#include <stdio.h>

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int linearSearch(int a[], int n, int search)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
            return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int search)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == search)
            return mid;
        else if (a[mid] < search)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int a[], int n, int search, int low, int high)
{
    int mid = (low + high) / 2;
    if (low >= high)
    {
        return -1;
    }
    if (a[mid] == search)
    {
        return mid;
    }
    else if (a[mid] < search)
    {
        return binarySearchRecursive(a, n, search, mid + 1, high);
    }
    else
    {
        return binarySearchRecursive(a, n, search, low, mid - 1);
    }
}
void main()
{
    int a[100];
    int n; // Total number of elements in array
    int i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value of a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    display(a, n);
    printf("%d\n", linearSearch(a, n, 3));
    printf("%d\n", binarySearch(a, n, 2));
}
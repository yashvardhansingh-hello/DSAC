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
}
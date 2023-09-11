#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indInsertion(int arr[], int *Usize, int Tsize, int index, int value)
{
    if (*Usize == Tsize)
    {
        printf("err'arr is full.'");
        return;
    }
    if (index < 0 || index >= *Usize)
    {
        printf("err'Index out of bounds.'");
        return;
    }
    for (int i = *Usize; i >= index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*Usize)++;
}

int indDeletion(int arr[], int *Usize, int Tsize, int index)
{
    if (*Usize == 0)
    {
        printf("err'Arr is empty.'");
        return -1;
    }
    if (index < 0 || index >= *Usize)
    {
        printf("err'Index out of bounds.'");
        return -1;
    }
    int temp = arr[index];
    for (int i = index; i <= *Usize; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*Usize)--;
    return temp;
}

int linearSearch(int arr[], int Usize, int value)
{
    for (int i = 0; i < Usize; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int Usize, int value)
{
    int low, high, mid;
    low = 0;
    high = Usize - 1;
    mid = ceil((low + high) / 2);
    while (1)
    {
        if (arr[low] == value)
            return low;
        if (arr[high] == value)
            return high;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] >= value)
            high = mid;
        if (arr[mid] < value)
            low = mid;
        mid = ceil((low + high) / 2);
        if (low == high || low < 0 || high >= Usize)
            break;
    }
    return -1;
}

int main()
{
    int arr[100] = {1, 2, 3, 4};
    int Usize = 4;
    int Tsize = 100;
    display(arr, Usize);
    indInsertion(arr, &Usize, Tsize, 1, 100);
    display(arr, Usize);
    indDeletion(arr, &Usize, Tsize, 1);
    display(arr, Usize);
    printf("The value 1 is at %d index\n", linearSearch(arr, Usize, 1));
    for (int i = 1; i <= 4; i++)
    {
        printf("The value %d is at %d index\n", i, binarySearch(arr, Usize, i));
    }
    return 0;
}
#include<stdio.h>

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void adaptiveBubbleSort(int* arr, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            isSorted = 0;
            }
        }
        if(isSorted) return;
    }
    
}

int main(){
    int arr[5] = {3, 1, 1, 4, 2};
    adaptiveBubbleSort(arr, 5);
    printArr(arr, 5);
    return 0;
}
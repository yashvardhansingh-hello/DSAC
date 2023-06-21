#include<stdio.h>
#include<stdlib.h>

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void selectionSort(int* arr, int n){
    int min;
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]< arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
}

int main(){
    int arr[] = {0, 6, 1, 2, 3};
    int n = 5;
    printArr(arr, n);
    selectionSort(arr, n);   
    printArr(arr, n);   
    return 0;
}
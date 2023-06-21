#include<stdio.h>

void printArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

void insertionSort(int *A, int n){
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n-1; i++)
    {
        key = A[i];
        j = i-1;
        // Loop for each pass
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int arr[] =  {7, 3, 3, 9, 1, 9, 7, 11};
    printArr(arr, 8);   
    insertionSort(arr, 8);
    printArr(arr, 8);   
    return 0;
}

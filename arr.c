#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};


void show(int *arr, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }printf("\n");
}

void setValue(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter Element at Index %d: ", i);
        scanf("%d", (arr+i));
    }
}

void insert(int* arr, int n, int index, int value) {
    if (index<0 || index>=n) {
        printf("err'Index out of Bounds.'");
        return ;
    }
    for(int i = n-2;i>=index;i--) {
        arr[i+1] = arr[i];
    }
    arr[index] = value;
}

int delete(int* arr, int n,  int index) {
    if (index>=n || index<0)
    {
        printf("err'Index out of Bounds.'");
        return 0;
    }
    int temp = arr[index];
    for(int i=index;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    return temp;
}   

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    setValue(arr, n);
    show(arr, n);
    insert(arr, n, 2, 4);
    show(arr, n);
    delete(arr, n, 2);
    show(arr, n);
    return 0;
}
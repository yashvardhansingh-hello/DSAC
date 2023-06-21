#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};


void createArray(struct myarray*a, int tsize, int usize) {
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = (int *) malloc(tsize*sizeof(int));

    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *) malloc(tsize*sizeof(int));
}

void show(struct myarray *a) {
    for (int i = 0; i < a-> used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
    
}

void setValue(struct myarray *a) {
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter Element %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
    
}

void insert_order_notIMP(struct myarray*a, int index, int value) {
    if (a->used_size == a->total_size) {
        printf("err'Array is Full'");
        return ;
    }
    if (a->total_size<=(index+1) || index<0)
    {
        printf("err'Index out of Bounds.'");
        return ;
    }
    int temp = (a->ptr)[index];
    (a->ptr)[index] = value;
    (a->ptr)[a->used_size] = temp;
    a->used_size++;
}

void insert_order_IMP(struct myarray * a, int index, int value){};

int deletion_order_notIMP(struct myarray * a, int index) {
    if (a->used_size == 0)
    {
        printf("err'Empty Array'");
        return 0;
    }
    
    if (a->total_size<=(index+1) || index<0)
    {
        printf("err'Index out of Bounds.'");
        return 0;
    }
    
    int val = (a->ptr)[index];
    (a->ptr)[index] = 0;
    int temp = (a->ptr)[a->used_size];
    (a->ptr)[a->used_size] = 0;
    (a->ptr)[index] = temp;
    a->used_size--;
    return val;
     
}

int main(){
    struct myarray marks;
    createArray(&marks, 10, 2);
    printf("We're running setVal now.\n");
    setValue(&marks);
    printf("\n\nThe show function starts\n\n\n");
    show(&marks);
    printf("\n\nThe insert function starts\n\n\n");
    insert_order_notIMP(&marks, 1, 3);
    show(&marks);
    printf("\n\nThe deletion function starts\n\n\n");
    printf("%d", deletion_order_notIMP(&marks, 2));
    show(&marks
    );

    return 0;
}
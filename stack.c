#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if (ptr->top == -1) return 1;
    else return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1) return 1;
    else return 0;
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)) {printf("Stack Underflow");return -1;}
    else{
        int val = ptr->arr[ptr->top];
        (ptr->top)--;
        return val;
    }
}

void push(struct stack* ptr, int value){
    if(isFull(ptr)){printf("Stack Overflow");}
    else{
        (ptr->top)++;
        ptr->arr[ptr->top] = value;
    }
}

int peek(struct stack* ptr, int index){
    int arrIndex = ptr->top - index +1;
    if(arrIndex>ptr->top){printf("Invalid Index");return -1;}
    else{
        return ptr->arr[arrIndex];
    }
}

int stackTop(struct stack* ptr){
   return ptr->arr[ptr->top]; 
}

int stackBottom(struct stack* ptr){
    return ptr->arr[0];
}

struct stack* buildStack(struct stack* s, int size){
    s->top=-1;
    s->size = size;
    s->arr = (int* )malloc(sizeof(int)*s->size);
    return s;
}

void main(){
    
    //Allocating Stack
    struct stack* s;
    s = buildStack(s, 20);

    push(s, 5);
    push(s, 5);
    push(s, 5);
    push(s, 5);
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }printf("\n");
    
}
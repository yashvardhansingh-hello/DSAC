#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct stack{
    int top;
    int size;
    struct Node* head;
};


int isEmpty(struct stack* ptr){
    if (ptr->top == -1) return 1;
    else return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1) return 1;
    else return 0;
}

void push(struct stack* ptr, int value){
    if(isFull(ptr)){printf("Stack Overflow");}
    else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = value;
        temp->next = ptr->head;
        ptr->head = temp;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){printf("Stack Underflow");return -1;}
    else{
        struct Node* temp = ptr->head;
        ptr->head = ptr->head->next;
        temp->next = NULL;
        return temp->data;
    }
}


void printLLst(struct Node*a) {
    while(a != NULL){
        printf("Element: %d\n", a->data);
        a = a->next;
    }
}

int stackTop(struct stack* s){
    return s->head->data;
}

int stackBottom(struct stack* s){
    struct Node* temp = s->head;
    while(temp->next != NULL){
        temp = temp->next;
    } return temp;
}

int peek(struct stack* s, int index){
    if(index>(s->top)){return -1;}
    else{
        struct Node* temp = s->head; 
        for (int i = 0; i < index; i++){
            temp = temp->next;
        } return temp->data;
    }
}

int main(){
    struct Node* head; 
    struct Node*second; 
    struct Node*third;

    // Allocating Memory to Nodes in the linked lsit in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Linking the Nodes
    head->data = 7;
    head ->next = second;
    second->data = 11;
    second ->next = third;
    third->data = 66;
    third ->next = NULL;

    struct stack* s;
    s->head = head;
    s->size = 20;
    s->top = 2;

    return 0;
}
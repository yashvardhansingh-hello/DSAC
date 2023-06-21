#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void printDLLst(struct Node* head){
    while(head != NULL){
        printf("ELement: %d\n", head->data);
        head = head->next;
    }
}

// struct Node* traverse(struct Node* head, int index){}

struct Node* insert(struct Node* head, struct Node* tail, int index, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(index==0){
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        return temp;
    }
    struct Node* ptr = head;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;   
    }
    temp->next = ptr;
    temp->prev = ptr->prev;
    ptr->prev->next = temp;
    ptr->prev = temp;
    return temp;
}

int main(){

    // Allocating Memory
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
        
    // Assigning values
    head->data = 7;
    second->data = 67;
    third->data = 69;
    tail->data = 420;

    // Linking Nodes
    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = tail;
    tail->next = NULL;
    tail->prev = third;

    return 0;

}
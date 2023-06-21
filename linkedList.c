#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void printLLst(struct Node*a) {
    while(a != NULL){
        printf("Element: %d\n", a->data);
        a = a->next;
    }
}

struct Node* LLstTraverse(struct Node* a, int index) {
    int i = 0;
    while(i < index){
        a = a->next;
        i++;
    }
    return a;
}

struct Node* insert(struct Node* head, int index, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    if(index == 0){
        temp->next = head;
        head = temp;
        return head;
    }
    struct Node* prev = LLstTraverse(head, index-1);
    if(prev->next == NULL) {
        prev->next = temp;
        temp->next = NULL;
        return head;
    }
    temp->next = prev->next;
    prev->next = temp;
    return head;
}

struct Node* insertAtIndex(struct Node* head, int index, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;    
    struct Node* prev = head;
    int i = 0;
    while (i != index-1)
    {
        prev = prev->next;
        i++;
    }
    temp->next = prev->next;
    prev->next = temp;
    return temp;
}

struct Node* delete(struct Node* head, int index){
    if(index ==0){
        struct Node* temp = head;
        head = head->next;
        temp->next = NULL;
        return temp;
    }
    struct Node* prev = LLstTraverse(head, index-1);
    struct Node* temp = prev->next;
    prev->next = temp->next;
    temp->next = NULL;
    return temp;
}



int main(){
    struct Node* head; 
    struct Node*second; 
    struct Node*third;

    // Allocating Memory to Nodes in the linked lsit in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Link First and Second Nodes
    head->data = 7;
    head ->next = second;

    // Link Second and Third Nodes
    second->data = 11;
    second ->next = third;

    // Terminate the List at Third Node
    third->data = 66;
    third ->next = NULL;

    printLLst(head);

    head = insert(head, 1, 5);
    printLLst(head);
    printf("Deleted: %d\n", delete(head, 1)->data);
    printLLst(head);
    return 0;
}
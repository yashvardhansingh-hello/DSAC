#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = head->next;
    head->next = temp;
    return temp;
}
struct Node* traverse(struct Node* head, int value) {
    struct Node* temp = head;
    do
    {
        if(temp->data == value) return temp;
        temp = temp->next;
    } while (temp != head);
    // temp->data = NULL;
    // temp->next = NULL;
    return temp;
}

void printCirLLst(struct Node* head) {
    struct Node* temp = head;
    do {
        printf("ELement: %d\n", temp->data);
        temp = temp->next;
    
    } while(head != temp);
}

int main(){
    
    // Allocating Memory
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));    
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));    
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));    

    // Giving values
    head->data = 4;
    second->data = 78;
    third->data = 34;
    
    // Linking Nodes
    head->next = second;
    second->next = third;
    third->next = head;

    printCirLLst(head);
    head = insert(head, 5);
    printCirLLst(head);
    printf("Elemnet found: %d\n", traverse(head, 5)->data);   
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct stack
{
    struct Node *head;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->head == NULL)
        return 1;
    return 0;
}

void push(struct stack *ptr, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = ptr->head;
    ptr->head = temp;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow");
        return -1;
    }
    struct Node *temp = ptr->head;
    ptr->head = ptr->head->next;
    temp->next = NULL;
    return temp->data;
}

void printLLst(struct stack *s)
{
    struct Node *temp = s->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct stack *buildStack(struct stack *s)
{
    s->head = NULL;
    return s;
}

int peek(struct stack *s)
{
    if (s->head == NULL)
        return -1;
    return s->head->data;
}

void main()
{
    struct stack *s = buildStack(s);
    push(s, 5);
    push(s, 5);
    push(s, 5);
    push(s, 5);
    printf("Peek: %d\n", peek(s));
    printLLst(s);
    printf("The Element removed: %d\n", pop(s));
}
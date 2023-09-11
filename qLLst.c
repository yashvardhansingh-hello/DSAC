#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printQueue(struct Node *a)
{
    while (a != NULL)
    {
        printf("Element: %d\n", a->data);
        a = a->next;
    }
}

struct Node *LLstTraverse(struct Node *a, int index)
{
    int i = 0;
    while (i < index)
    {
        a = a->next;
        i++;
    }
    return a;
}

struct queue
{
    int size;
    int currrentSize;
    struct Node *f;
    struct Node *r;
};

int isEmpty(struct queue *q)
{
    if (q->r == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->currrentSize == q->size)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value)
{
    if (q->f == NULL)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->data = value;
        q->f = new;
        q->r = new;
        q->currrentSize++;
    }
    else
    {
        if (isFull(q))
        {
            printf("This Queue is full\n");
        }
        else
        {
            struct Node *new = (struct Node *)malloc(sizeof(struct Node));
            new->data = value;
            new->next = NULL;
            q->r->next = new;
            q->r = new;
            q->currrentSize++;
        }
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
        return -1;
    }
    else
    {
        struct Node *temp = q->f;
        q->f = q->f->next;
        q->currrentSize--;
        return temp->data;
    }
}

int main()
{
    struct queue q;
    q.size = 4;
    q.currrentSize = 0;
    q.f = q.r = NULL;
    enqueue(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 8);

    return 0;
}
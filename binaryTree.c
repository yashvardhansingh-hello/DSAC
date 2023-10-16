#include <stdio.h>
#include <stdlib.h>
#define qSIZE 300

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// DFS
void printInorder(struct node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}

void printPreorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(struct node *root)
{
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->value);
}

struct node **createQueue(int *front, int *rear)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *) * qSIZE);
    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_Node)
{
    queue[*rear] = new_Node;
    (*rear)++;
}

struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

void printLevelOrder(struct node *root)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp = root;

    while (temp)
    {
        printf("%d ", temp->value);
        if (temp->left)
        {
            enQueue(queue, &rear, temp->left);
        }
        if (temp->right)
        {
            enQueue(queue, &rear, temp->right);
        }
        temp = deQueue(queue, &front);
    }
}

int maxDepth(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);
        if (lheight < rheight)
        {
            return (rheight + 1);
        }
        else
        {
            return (lheight + 1);
        }
    }
}

void insertNode(struct node *root, int data)
{
    struct node *temp = newNode(data);

    if (root == NULL)
    {
        root = temp;
        return;
    }
    else
    {
        if (root->left == NULL)
        {
            root->left = temp;
            return;
        }
        if (root->right == NULL)
        {
            root->right = temp;
            return;
        }
    }
}

void main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    // root->right->right = newNode(2);
    printInorder(root);
    printf("\n");
    printPostorder(root);
    printf("\n");
    printPreorder(root);
    printf("\n");
    // printLevelOrder(root);
    // printf("\n");
    printf("The Depth: %d\n", maxDepth(root));
    insertNode(root, 1);
    printInorder(root);
    printf("\n");

    // printInorder(root);
}
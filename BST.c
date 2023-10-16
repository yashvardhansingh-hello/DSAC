#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertNode(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    else
    {
        if (value < root->data)
        {
            root->left = insertNode(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct node *searchBST(struct node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    if (root->data < value)
    {
        return searchBST(root->right, value);
    }
    return searchBST(root->left, value);
}

/*
void storeBSTNodes(struct node *root, struct node *nodes[], int i)
{
    if (!root)
    {
        return;
    }
    storeBSTNodes(root->left, nodes, i);
    nodes[i] = root;
    i++;
    storeBSTNodes(root->left, nodes, i);
}

struct node *buildTreeUtils(struct node *nodes[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct node *root = nodes[mid];
    root->left = buildTreeUtils(nodes, start, mid - 1);
    root->left = buildTreeUtils(nodes, mid + 1, end);
    return root;
}

struct node *buildTree(struct node *root)
{
    struct node *nodes[50];
    storeBSTNodes(root, nodes, 0);
    int n = sizeof(nodes) / sizeof(nodes[0]);
    return buildTreeUtils(nodes, 0, n - 1);
}
*/

void main()
{
    struct node *root = createNode(1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    inOrder(root);
    printf("\n");
    if (searchBST(root, 3))
    {
        printf("\n%d \n", searchBST(root, 3)->data);
    }
    // root = buildTree(root);
    // inOrder(root);
    // Incomplete trying to balance a BST
}

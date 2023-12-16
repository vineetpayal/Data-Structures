#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
typedef struct node node;

node *createNode(int key)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }

    if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int secondLargest(node *root, int arr[], int *count)
{
    if (root == NULL)
    {
        return 0;
    }

    secondLargest(root->left, arr, count);
    arr[(*count)++] = root->key;
    secondLargest(root->right, arr, count);

    for (int i = 0; i < 5 / 2; i++)
    {
        arr[i] = arr[5 - 1 - i];
    }

    return arr[1];
}

void main()
{
    int arr[5];
    int count = 0;

    node *root = createNode(5);
    insert(root, 4);
    insert(root, 6);
    insert(root, 10);
    insert(root, 12);

    inorder(root);

    printf("\nSecond largest: %d\n", secondLargest(root, arr, &count));
}
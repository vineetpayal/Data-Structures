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
    node *newNode = (node *)malloc(sizeof(node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
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
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

int search(node *root, int key)
{
    if (root->key == key)
    {
        return root->key;
    }

    if (key < root->key)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void main()
{
    node *root = NULL;
    root = createNode(9);
    insert(root, 6);
    insert(root, 4);
    insert(root, 3);
    insert(root, 10);
    insert(root, 2);
    insert(root, 12);
    inorder(root);
    int result = search(root, 10);
    printf("\n%d found!", result);
}
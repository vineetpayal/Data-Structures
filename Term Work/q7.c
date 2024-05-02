/*
Q7. W.A.P. to create a binary search tree and perform following operations:
1) Search a particular key.
2) Delete a node from the tree.
3) Find total number of leaf nodes
4) Find height of a binary search tree
5) Count total numbers of nodes from right hand side of root node
6) Kth largest element without doing any modification in Binary Search Tree.
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
typedef struct node node;

node *createNode(int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->key)
    {
        root->left = insert(root->left, value);
    }
    else if (value >= root->key)
    {
        root->right = insert(root->right, value);
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

node *minValueNode(node *n)
{
    node *current = n;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int findHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int countLeafNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countRight(node *root)
{
    static int count = 0;

    if (root == NULL)
    {
        return 0;
    }

    countRight(root->right);

    count++;

    return count;
}

void findKthLargest(node *root, int k, int *count)
{
    if (root == NULL || *count >= k)
    {
        return;
    }

    findKthLargest(root->right, k, count);

    (*count)++;

    if (*count == k)
    {
        printf("Kth largest element is: %d\n", root->key);
        return;
    }

    findKthLargest(root->left, k, count);
}

void main()
{
    node *root = NULL;
    int count = 0;
    int choice, key;

    while (1)
    {
        printf("\n\tInstructions\n");
        printf("\nPress:\nInsert: 1\nDelete: 2\nTotal number of leaf nodes: 3");
        printf("\nHeight of BST: 4\nTotal nodes in RHS of root: 5\nTo find Kth largest element: 6\nClick 7 to exit.\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            if (root == NULL)
            {
                root = createNode(key);
            }
            else
            {
                insert(root, key);
            }
            break;

        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteNode(root, key);
            printf("Inorder Transversal: ");
            inorder(root);
            break;

        case 3:
            printf("Total leaf node: %d\n", countLeafNodes(root));
            break;

        case 4:
            printf("Height of BST: %d\n", findHeight(root));
            break;
        case 5:
            printf("Total nodes in RHS of root: %d\n", countRight(root));

        case 6:
            printf("Enter K: ");
            scanf("%d", &key);
            findKthLargest(root, key, &count);
            break;
        case 7:
            exit(0);

        default:
            printf("Invalid Instruction\n");
        }
    }
}
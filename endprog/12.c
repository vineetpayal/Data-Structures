#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node *pre(node *root)
{
    while (root->right)
        root = root->right;
    return root;
}
node *delete(node *root, int key)
{

    if (root->val == key)
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
        else
        {
            node *pred = pre(root->left);
            root->val = pred->val;
            root->left = delete (root->left, pred->val);
            return root;
        }
    }

    if (root->val > key)
        root->left = delete (root->left, key);
    else
        root->right = delete (root->right, key);

    return root;
}
node *insert(int key, node *root)
{
    if (!root)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->val = key;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (key < root->val)
        root->left = insert(key, root->left);
    else
        root->right = insert(key, root->right);

    return root;
}
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
void preorder(node *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    inorder(root->left);
    inorder(root->right);
}
void postorder(node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}
int largest(node *root)
{
    while (root->right)
        root = root->right;
    return root->val;
}
int smallest(node *root)
{
    while (root->left)
        root = root->left;
    return root->val;
}
void createBST(node **root)
{
    int ch = 1;
    int data;
    while (ch)
    {
        printf("Enter data:");
        scanf("%d", &data);
        *root = insert(data, *root);
        printf("Insert another value?");
        scanf("%d", &ch);
    }
}
int main()
{
    node *root = NULL;
    printf("Creating Tree:\n");
    createBST(&root);
    inorder(root);
    int key;
    printf("\nEnter the value to be deleted:");
    scanf("%d", &key);
    root = delete (root, key);
    printf("\nInorder traversal:\n");
    inorder(root);
    int l = largest(root);
    int s = smallest(root);
    printf("\n\nPreorder:");
    preorder(root);
    printf("\nInorder:");
    inorder(root);
    printf("\nPostorder:");
    postorder(root);
    printf("\n");
    printf("\n%d is the smallest and %d is the largest", s, l);

    printf("\nVineet Payal, A1(68)\n");

    return 0;
}

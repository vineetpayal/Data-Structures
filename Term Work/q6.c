/*
Q6.Write a C program to create two link lists positive and negative from Original linked list, so that
positive linked list contains all positive elements and negative linked list contains negative elements.
Positive and negative linked lists should use the node of existing original linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

node *createNode(int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int value)
{
    node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void split(node *original, node **pos, node **neg)
{
    node *temp = original;
    while (temp != NULL)
    {
        if (temp->data >= 0)
        {
            insert(pos, temp->data);
        }
        else
        {
            insert(neg, temp->data);
        }
        temp = temp->next;
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void main()
{
    node *head = NULL;
    node *pos = NULL, *neg = NULL;
    int choice, num;

    while (1)
    {
        printf("\n\tInstructions\n");
        printf("Press 1 to insert.\nPress 2 to split into positive and negative.\nPress 3 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &num);
            insert(&head, num);
            break;

        case 2:
            split(head, &pos, &neg);
            printf("Original: ");
            display(head);
            printf("Positive: ");
            display(pos);
            printf("Negative: ");
            display(neg);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid instruction.");
        }
    }
}
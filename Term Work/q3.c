/*
Q3.Write a C program to create a single linked list then input a value V, partition it such that all nodes less
than V come before nodes greater than or equal to V.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insert(node **head, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
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

node *partition(node **head, int v)
{
    node *temp = *head;
    node *small = NULL;
    node *great = NULL;
    node *vNode = NULL;

    while (temp != NULL)
    {
        if (temp->data < v)
        {
            insert(&small, temp->data);
        }
        else
        {
            insert(&great, temp->data);
        }
        temp = temp->next;
    }

    if (small == NULL)
    {
        return great;
    }
    else
    {
        node *temp = small;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = great;
    }
    return small;
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

void main()
{
    node *head = NULL;
    int choice, num;

    while (1)
    {
        printf("\n\tInstructions:\nPress 1 to insert\nPress 2 to enter value of V\nPress 3 to display Partitioned list\nPress 4 to exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &num);
            insert(&head, num);
            break;
        case 2:
            printf("Enter V: ");
            scanf("%d", &num);
            head = partition(&head, num);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Instruction\n");
        }
    }
}
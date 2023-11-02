#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};
typedef struct node node;

void insert(node **head, node **last, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
        *last = newNode;
    }
    else if ((*head)->data > value)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        *head = newNode;
    }
    else if ((*last)->data < value)
    {
        newNode->next = NULL;
        newNode->prev = *last;
        (*last)->next = newNode;
        *last = newNode;
    }

    else
    {
        node *temp = *head;
        while (temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void display(node *head, node *last)
{
    node *temp = head;
    while (temp != last)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int delete(node **head, node **last, int value)
{
    if (*head == NULL)
    {
        printf("List is empty");
    }
    else if ((*head)->data == value)
    {
        int data = (*head)->data;
        (*head)->next->prev = NULL;
        *head = (*head)->next;
        return data ;
    }
    else if ((*last)->data == value)
    {
        int data = (*last)->data;
        *last = (*last)->prev;
        return data;
    }
    else
    {
        node *temp = *head;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                int data = temp->data;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return data;
            }
            temp = temp->next;
        }
    }
}

void main()
{
    node *head = NULL;
    node *last = NULL;

    int choice;
    int value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete by value\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(&head, &last, value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            int val = delete (&head, &last, value);
            printf("Deleted value:%d\n", val);
            break;
        case 3:
            display(head, last);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
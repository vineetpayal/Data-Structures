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
        *head = newNode;
        newNode->next = *head;
        *last = newNode;
    }
    else if ((*head)->data > value)
    {
        newNode->next = *head;
        newNode->prev = *last;
        (*head)->prev = newNode;
        *head = newNode;
        (*last)->next = *head;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head && temp->next->data < value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        if (temp->next == *head)
        {
            *last = newNode;
        }
    }
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
        (*head)->next->prev = *last;
        (*last)->next = (*head)->next;
        *head = (*head)->next;
        return data;
    }
    else if ((*last)->data == value)
    {
        int data = (*last)->data;
        (*last)->prev->next = (*last)->next;
        *last = (*last)->prev;
        (*head)->prev = *last;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head)
        {
            if (temp->data == value)
            {
                int data = temp->data;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                return data;
            }

            temp = temp->next;
        }

        printf("No such element found\n");
    }
}

void display(node *head, node *last)
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
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
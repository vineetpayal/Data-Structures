#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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
        *head = newNode;
        (*last)->next = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head && temp->next->data < value)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == *head)
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
        *head = (*head)->next;
        (*last)->next = *head;
        return data;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head)
        {
            if (temp->next->data == value)
            {
                int data = temp->next->data;
                temp->next = temp->next->next;
                *last = temp;
                return data;
            }
            temp = temp->next;
        }
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
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
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
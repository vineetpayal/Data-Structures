#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

void insert(node *head, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else if ((head)->data > value)
    {
        newNode->next = head;
        (head) = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int delete(node **head, int value)
{
    if (*head == NULL)
    {
        printf("Nothing to delete...List is empty");
        return -1;
    }
    else if ((*head)->data == value)
    {
        int data = (*head)->data;
        *head = (*head)->next;
        return data;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            if (temp->next->data == value)
            {
                int data = temp->next->data;
                temp->next = temp->next->next;
                return data;
            }
            temp = temp->next;
        }

        printf("No such element found\n");
    }
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

void main()
{
    node *head = NULL;
    int choice;
    int value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete by value\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(head, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                int val = delete(&head, value);
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
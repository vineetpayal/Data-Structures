/*
Write a C program to create two single linked lists, and then write another function to subtract two
numbers represented as linked list.
List1->; 8->9->7->NULL (First Number: 897)
List2->: 1->4->5->NULL (Second Number: 145)
Output->:752
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

void insertAtBeg(node **head, int value)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    newNode->next = *head;
    *head = newNode;
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

node *subtract(node *num1, node *num2)
{
    node *result = NULL;
    node *temp;
    int borrow = 0;

    while (num1 != NULL || num2 != NULL)
    {
        int x = (num1 != NULL) ? num1->data : 0;
        int y = (num2 != NULL) ? num2->data : 0;

        int diff = x - y - borrow;
        borrow = 0;

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }

        insert(&result, diff);

        if (num1 != NULL)
            num1 = num1->next;
        if (num2 != NULL)
            num2 = num2->next;
    }

    // Remove leading zeros
    while (result != NULL && result->data == 0)
    {
        temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}

node *toLinkedList(int num)
{
    node *numList = NULL;
    while (num != 0)
    {
        // Number is extracted from last digit
        // so inserting at beginning to avoid reversing the linked last later.
        insertAtBeg(&numList, num % 10);
        num = num / 10;
    }
    return numList;
}

void main()
{
    node *num1 = NULL;
    node *num2 = NULL;
    node *result = NULL;

    int choice, num;

    while (1)
    {
        printf("\n\tInstructions:\n");
        printf("\nPress 1 to insert num1.\nPress 2 to insert num2.\nPress 3 to display result.\nPress 4 to exit.\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter num1: ");
            scanf("%d", &num);
            num1 = toLinkedList(num);
            break;
        case 2:
            printf("Enter num2: ");
            scanf("%d", &num);
            num2 = toLinkedList(num);
            break;
        case 3:
            if (num1 != NULL && num2 != NULL)
            {
                result = subtract(num1, num2);
                display(result);
            }
            else
            {
                printf("\nInvalid number entered!\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid instruction");
        }
    }
}
/*Q5. Write a C program to craeate a single linked list , like L0 -> L1 -> … -> Ln-1 -> Ln. Write another C
fucntion to rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2
-> Ln-2 .You are required to do this in place without altering the nodes’ values.
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

node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void rearrange(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *rev = reverse(slow->next);
    slow->next = NULL;

    while (rev != NULL)
    {
        node *temp1 = head->next;
        node *temp2 = rev->next;

        head->next = rev;
        rev->next = temp1;

        head = temp1;
        rev = temp2;
    }
}

void main()
{
    node *head = NULL;
    int choice, num;
    while (1)
    {
        printf("\n\tInstructions\n");
        printf("Press 1 to insert.\nPress 2 to rearrange.\nPress 3 to exit.\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &num);
            insert(&head, num);
            display(head);
            break;
        case 2:
            rearrange(head);
            display(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Instruction\n");
        }
    }
}
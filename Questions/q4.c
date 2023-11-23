/*
Given the head of a linked list, remove the n th node from the end of the list and return its
head.
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
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

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

int deleteFromEnd(node *head, int n)
{
    int lengthFromBeg = length(head) - n;

    node *temp = head;

    for (int i = 1; i < lengthFromBeg; i++)
    {
        temp = temp->next;
    }
    int deletedElement = temp->next->data;
    temp->next = temp->next->next;
    return deletedElement;
}

void main()
{
    node *head = NULL;
    int n;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 9);
    insert(&head, 10);

    display(head);

    printf("Enter nth element to delete from end: ");
    scanf("%d", &n);

    int deleted = deleteFromEnd(head, n);

    printf("\n%d is deleted from the list\n", deleted);

    display(head);
}

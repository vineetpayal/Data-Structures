/*
Q8. Write a program to add of two polynomials of degree n, using linked list
p1 = first polynomial
p2 = second polynomial
Find out p3= p1+p2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int coeff;
    int deg;
    struct node *next;
};
typedef struct node node;

node *createNode(int coeff, int deg)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->deg = deg;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int coeff, int deg)
{
    node *newNode = createNode(coeff, deg);
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

node *createPolynomialLinkedList(char *s)
{
    node *head = NULL;
    for (int i = 0; *(s + i) != '\0'; i++)
    {
        if (*(s + i) == 'x')
        {
            insert(&head, *(s + i - 1) - '0', *(s + i + 1) - '0');
        }
    }
    return head;
}

node *addPolynomial(node **p1, node **p2)
{
    node *t1 = *p1;
    node *t2 = *p2;
    node *result = NULL;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->deg == t2->deg)
        {
            insert(&result, t1->coeff + t2->coeff, t1->deg);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->deg > t2->deg)
        {
            t1 = t1->next;
        }
        else if (t2->deg > t1->deg)
        {
            t2 = t2->next;
        }
    }

    return result;
}

void display(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        printf("%dx%d+", temp->coeff, temp->deg);
        temp = temp->next;
    }
    printf("%dx%d", temp->coeff, temp->deg);
}

void main()
{
    int choice;
    char s1[50];
    char s2[50];
    node *p1 = NULL;
    node *p2 = NULL;
    node *result = NULL;

    while (1)
    {
        printf("\n\tInstructions\n");
        printf("\nPress 1 to enter p1.\nPress 2 to enter p2.\nPress 3 to display result.\nPress 4 to exit.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter P1: ");
            scanf("%s",s1);
            p1 = createPolynomialLinkedList(s1);
            display(p1);
            break;

        case 2:
            printf("Enter P2: ");
            scanf("%s",s2);
            p2 = createPolynomialLinkedList(s2);
            display(p2);
            break;

        case 3:
            result = addPolynomial(&p1, &p2);
            display(result);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Instruction\n");
        }
    }
}
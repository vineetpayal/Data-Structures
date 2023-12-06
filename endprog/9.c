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
    char s1[50];
    char s2[50];
    printf("Enter P1: ");
    gets(s1);
    printf("Enter P2: ");
    gets(s2);
    node *p1 = createPolynomialLinkedList(s1);
    node *p2 = createPolynomialLinkedList(s2);

    node *result = addPolynomial(&p1, &p2);

    display(result);

    printf("\nVineet Payal, A1(68)\n");
}
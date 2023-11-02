#include <stdio.h>
#define MAX 20

void enqueue(int q[], int *f, int *b, int value)
{
    if (*b == MAX - 1)
    {
        printf("Queue is full");
    }
    else
    {
        *f = 0;
        (*b)++;
        q[*b] = value;
    }
}

int dequeue(int q[], int *f)
{
    if (*f == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        int result = q[*f];
        (*f)++;
        return result;
    }
}

void displayQueue(int q[], int *f, int *b)
{
    for (int i = *f; i <= *b; i++)
    {
        printf("%d ", q[i]);
    }
}

void main()
{
    int queue[MAX];
    int f = -1, b = -1;
    enqueue(queue, &f, &b, 1);
    enqueue(queue, &f, &b, 2);
    enqueue(queue, &f, &b, 3);
    enqueue(queue, &f, &b, 4);
    enqueue(queue, &f, &b, 5);
    displayQueue(queue, &f, &b);
    int r = dequeue(queue, &f);
    printf("\nAfter dequeue: \n");
    displayQueue(queue, &f, &b);
    printf("\nThe dequed value: %d", r);
    printf("\nVineet Payal, A1(68)\n");
}
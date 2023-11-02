#include <stdio.h>
#define MAX 5

void enqueue(int q[], int value, int *f, int *r)
{
    if (*f == -1)
    {
        *f = 0;
        *r = 0;
        q[*r] = value;
    }
    else if ((*r + 1) % MAX == *f)
    {
        printf("Queue is full");
    }
    else
    {
        *r = (*r + 1) % MAX;
        q[*r] = value;
    }
}

int dequeue(int q[], int *f, int *r)
{
    if (*f == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    else if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        int temp = q[*f];
        *f = (*f + 1) & MAX;
        return temp;
    }
}

void display(int q[], int f, int r)
{
    if (f == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        int i = f;
        while (i != r + 1)
        {
            printf("%d ", q[i]);
            i = (i + 1) % MAX;
        }
    }
    printf("\n");
}

void main()
{
    int queue[MAX];
    int f = -1, r = -1;

    enqueue(queue, 1, &f, &r);
    enqueue(queue, 2, &f, &r);
    enqueue(queue, 3, &f, &r);
    display(queue, f, r);
    int result = dequeue(queue, &f, &r);
    printf("After dequeue: \n");
    display(queue, f, r);
    printf("\nElement dequeued is: %d", result);
    printf("\nVineet Payal, A1(68)\n");
}
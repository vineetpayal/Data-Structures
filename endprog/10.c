#include <stdio.h>
#include <string.h>
void push(char st[], int *top, int ch)
{
    st[++(*top)] = ch;
}
void pop(int *top)
{
    if (*top == -1)
        printf("Underflow");
    else
        (*top)--;
}

char Top(char st[], int top)
{
    if (top == -1)
        return '?';
    else
        return st[top];
}
int Empty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    char stack[100];
    int top = -1;
    char str[100];
    char ch;
    printf("Enter the string:");
    scanf("%s", str);
    strcpy(str, strrev(str));
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a')
            push(stack, &top, str[i]);
        else if (str[i] == 'a')
        {
            ch = Top(stack, top);
            if (ch == '?')
            {
                printf("Invalid");
                return 0;
            }
            pop(&top);
        }
    }
    if (Empty(top))
        printf("Valid");
    else
        printf("Invalid");

    printf("\nVineet Payal, A1(68)\n");
    return 0;
}

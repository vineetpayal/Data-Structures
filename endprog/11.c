#include <stdio.h>
int main()
{
    printf("Enter the size\n");
    int size;
    scanf("%d ", &size);
    int arr[size];
    int j, k;
    int flag1 = 0, flag2 = 0;
    k = size - 1;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 2 && !flag1)
        {
            j = i;
            flag1 = 1;
        }
        if (arr[i] == 3 && !flag2)
        {
            k = i;
            flag2 = 1;
        }
    }
    int i = 0;
    while (arr[i] == 1 && arr[j] == 2 && arr[k] == 3)
    {
        i++;
        j++;
        k++;
    }
    if (arr[i] == 2 && arr[j] == 3 && k == size)
        printf("valid");
    else
        printf("Invalid");

    printf("\nVineet Payal, A1(68)\n");
}

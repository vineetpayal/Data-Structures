/*
Q9. Write a C program to sort a sequence of characters given by user in an array, using Quick sort
technique.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to partition the array and return the pivot index
int partition(char arr[], int low, int high)
{
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(char arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void display(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char arr[n];
 
    printf("Enter the characters: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    display(arr, n);

    return 0;
}

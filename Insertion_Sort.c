#include <stdio.h>
#include <stdlib.h>

int *initArray(int size)
{
    int *array = calloc(size, sizeof(int));
    return array;
}

void fillArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void displayArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int *array, int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];

        for (j = i - 1; j >= 0 && key < array[j]; j--)
        {
            displayArray(array, size);
            array[j + 1] = array[j];
        }
        array[j + 1] = key;
    }
}

int main()
{
    printf("\nEnter the number of elements: ");
    int size;
    scanf("%d", &size);
    int *array = initArray(size);
    printf("Enter the elemets of the array:\n");
    fillArray(array, size);

    printf("The elemets in the array are:\n");
    displayArray(array, size);

    printf("Sorting the array...\n");
    insertionSort(array, size);
    displayArray(array, size);

    printf("Press any key to Exit: ");
    scanf("%d", &size);
    free(array);
    return 0;
}
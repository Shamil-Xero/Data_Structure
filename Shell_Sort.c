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

void shellSort(int *array, int size)
{
    int gap, i, j, temp;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
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

    printf("After sorting the array:\n");
    shellSort(array, size);
    displayArray(array, size);

    free(array);
    return 0;
}
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

void countingSort(int *array, int size, int exp)
{
    int count[10] = {0};
    int output[size];
    for (int i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void radixSort(int *array, int size)
{
    int max = getMax(array, size);
    int exp = 1;
    while (max / exp > 0)
    {
        countingSort(array, size, exp);
        exp *= 10;
    }
}

int getMax(int *array, int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    printf("\nEnter the number of elements: ");
    int size;
    scanf("%d", &size);
    int *array = initArray(size);
    printf("Enter the elements of the array:\n");
    fillArray(array, size);
    printf("The elements in the array are:\n");
    displayArray(array, size);
    printf("After sorting the array:\n");
    radixSort(array, size);
    displayArray(array, size);
    free(array);
    return 0;
}
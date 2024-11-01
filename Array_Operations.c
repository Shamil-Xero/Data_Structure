#include <stdio.h>
#include <stdlib.h>

int size, c_size = 0, choice;

void fillArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

void displayArray(int *array, int c_size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int FullOrEmpty()
{
    if (size == c_size)
    {
        printf("Array is full!");
        return 1;
    }
    else if (c_size == 0)
    {
        printf("Array is Empty!");
        return 0;
    }
    else
    {
        return c_size;
    }
}

void Insert_Element(int array[size])
{
    if (FullOrEmpty() == 1)
    {
        printf(" Cannot insert element.\n");
    }
    else
    {
        int i, position, value;

        printf("\nEnter the position where you want to insert the element: ");
        scanf("%d", &position);

        printf("\nEnter the value to insert: ");
        scanf("%d", &value);

        if (position < 1)
        {
            position = 1;
            printf("\nAdded the element at the Start\n");
        }
        else if (position > c_size)
        {
            position = c_size;
            printf("\nAdded the element at the end\n");
        }

        for (i = c_size - 1; i >= position - 1; i--)
        {
            array[i + 1] = array[i];
        }

        array[position - 1] = value;
        c_size++;

        Display_Elements(array);
    }
}

void Delete_Element(int array[size])
{
    if (FullOrEmpty() == 0)
    {
        printf(" Cannot delete element.\n");
    }
    else
    {
        int i, position;

        printf("\nEnter the position where you want to delete the element: ");
        scanf("%d", &position);

        if (position > c_size)
        {
            printf("\nDeleted the last element\n");
            position = c_size;
        }
        else if (position < 1)
        {
            printf("\nDeleted the first element\n");
            position = 1;
        }

        for (i = position - 1; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }

        c_size--;

        Display_Elements(array);
    }
}

int main()
{

    printf("\n\nEnter the size of the array: ");
    scanf("%d", &size);
    int array[size];

    printf("Enter the elements:\n");
    fillArray(array, size);

    do
    {
        printf("\nOperations:\n\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("4. Display Elements\n");
        printf("0. TO EXIT...\n");
        printf("\nYour Choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            Insert_Element(array);
            break;
        case 2:
            Delete_Element(array);
            break;
        case 3:
            printf("\nElements in the array: ");
            displayArray(array, c_size);
            printf("\nCurrent_Size: %d", c_size);

            break;
        case 0:
            printf("\nExiting the program...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}

// void Search_Element(int array[size])
// {

//     if (FullOrEmpty() == 0)
//     {
//         printf(" No elements to search.\n");
//     }
//     else
//     {
//         int i, search_element, found_element = 0;
//         printf("\nEnter the element to search: ");
//         scanf("%d", &search_element);
//         for (i = 0; i < c_size; i++)
//         {
//             if (array[i] == search_element)
//             {
//                 printf("\nThe element %d is found on position no %d\n\n", search_element, i + 1);
//                 found_element = 1;
//             }
//         }
//         if (found_element == 0)
//         {
//             printf("\nThe element %d is not found in the array.\n\n\n", search_element);
//         }
//     }
// }

// void Sort_Array(int array[size]) {
//     int i, j, temp;
//     char order;
//     if (FullOrEmpty() == 0) {
//         printf(" No elements to sort.\n");
//         return;
//     }
//     printf("Ascending or Descending order (A/D): ");
//     scanf("%s", &order);
//     if (order != 'A' || order != 'a' || order != 'D' || order != 'd') {
//         printf("\nInvalid choice. Please try again.\n");
//         return;
//     }

//     for (i = 0; i < c_size - 1; i++) {
//         for (j = 0; j < c_size - i - 1; j++) {
//             if (order == 'A' || order == 'a' && array[j] > array[j + 1]) {
//                 temp = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = temp;
//             } else if (order == 'D' || order == 'd' && array[j] < array[j + 1]) {
//                 temp = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = temp;
//            }
//         }
//     }
//     printf("\nSorted array: ");
//     Display_Elements(array);

// }

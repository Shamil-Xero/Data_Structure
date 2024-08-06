#include<stdio.h>
int Total_size, Current_size = 0, choice1;

void Insert_Element(int array[]);
void Delete_Element(int array[]);
void Search_Element(int array[]);
void Sort_Array(int array[]);
void Display_Elements(int array[]);
int main() {

    printf("\n\nEnter the size of the array: ");
    scanf("%d", &Total_size);
    int array[Total_size];

    if (Total_size <= 0) {
        printf("\nSorry, Cannot create array :(\n");
    } else {
        printf("Enter the %d elements:\n", Total_size);
        for (int i = 0; i < Total_size; i++) {
            scanf("%d", &array[i]);
            Current_size++;
        }
        Display_Elements(array);

        do{    
            printf("\nOperations to do on the Array:\n\n");
            printf("1. Insert Element\n");
            printf("2. Delete Element\n");
            printf("3. Search Element\n");
            printf("4. Display Elements\n");
            printf("5. Sort Array\n");
            printf("0. TO EXIT...\n");
            printf("\nYour Choice : ");
            scanf("%d", &choice1);
            printf("\n");

            switch (choice1) {
                case 1:
                    Insert_Element(array);
                    break;
                case 2:
                    Delete_Element(array);
                    break;
                case 3:
                    Search_Element(array);
                    break;
                case 4:
                    Display_Elements(array);
                    break;
                case 5:
                    Sort_Array(array);
                    break;
                case 0:
                    printf("\nExiting the program...\n");
                    break;

                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
        } while (choice1 != 0);
    }
    printf("\n\n");
    return 0;
}

int FullOrEmpty() {
    if (Total_size == Current_size) {
        printf("Array is full!");
        return 1;
    } else if (Current_size == 0) {
        printf("Array is Empty!");
        return 0;
    } else {
        return Current_size;
    }
}

void Insert_Element(int array[Total_size]) {
    if (FullOrEmpty() == 1) {
        printf(" Cannot insert element.\n");
    } else {
        int i, position, value;

        printf("\nEnter the position where you want to insert the element: ");
        scanf("%d", &position);

        printf("\nEnter the value to insert: ");
        scanf("%d", &value);

        
        if (position < 1){
            position = 1;
            printf("\nAdded the element at the Start\n");
        } 
        else if (position > Current_size) {
            position = Current_size;
            printf("\nAdded the element at the end\n");
        }

        for (i = Current_size - 1; i >= position - 1; i--) {
            array[i + 1] = array[i];
        }

        array[position - 1] = value;
        Current_size++;

        Display_Elements(array);
    }
}

void Delete_Element(int array[Total_size]) {
    if (FullOrEmpty() == 0) {
        printf(" Cannot delete element.\n");
    } 
    else {
        int i, position;

        printf("\nEnter the position where you want to delete the element: ");
        scanf("%d", &position);

        if (position > Current_size) {
            printf("\nDeleted the last element\n");
            position = Current_size;
        }
        else if (position < 1){
            printf("\nDeleted the first element\n");
            position = 1;
        }

        for (i = position - 1; i < Total_size - 1; i++) {
            array[i] = array[i + 1];
        }

        Current_size--;

        Display_Elements(array);
    }
}


void Search_Element(int array[Total_size]) {

    if (FullOrEmpty() == 0) {
        printf(" No elements to search.\n");
    }
    else {
        int i, search_element, found_element = 0;
        printf("\nEnter the element to search: ");
        scanf("%d", &search_element);
        for (i = 0; i < Current_size; i++){
            if (array[i] == search_element) {
                printf("\nThe element %d is found on position no %d\n\n", search_element, i+1);
                found_element = 1;
            }
        }
        if (found_element == 0)
        {
            printf("\nThe element %d is not found in the array.\n\n\n", search_element);
        }
            
    }
}

void Sort_Array(int array[Total_size]) {
    int i, j, temp;
    char choice2;
    if (FullOrEmpty() == 0) {
        printf(" No elements to sort.\n");
    } 
    else {
        printf("Ascending or Descending order (A/D): ");
        scanf("%s", &choice2);
        if (choice2 == 'A' || choice2 == 'a'){
            for (i = 0; i < Current_size - 1; i++) {
                for (j = 0; j < Current_size - i - 1; j++) {
                    if (array[j] > array[j + 1]) {
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }
        else if (choice2 == 'D' || choice2 == 'd'){
            for (i = 0; i < Current_size - 1; i++) {
                for (j = 0; j < Current_size - i - 1; j++) {
                    if (array[j] < array[j + 1]) {
                        temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }
        else {
            printf("\nInvalid choice for sorting order. Please choose A or D.\n");
        }
        
        printf("\nSorted array: ");
        Display_Elements(array);
    }
}

void Display_Elements(int array[Total_size]) {
    if (FullOrEmpty() == 0) {
        printf(" No elements to display.\n");
    } 
    else {
        printf("\nElements in the array: ");
        for (int i = 0; i < Current_size; i++) {
            printf("%d ", array[i]);
        }
        printf("\nCurrent_Size: %d", Current_size);
    }
}

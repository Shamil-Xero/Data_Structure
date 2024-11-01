#include <stdio.h>
#include <stdlib.h>

int *initArray(int size){
    int *array = calloc(size, sizeof(int));
    return array;
}

void fillArray(int *array, int size){
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

int linearSearch(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    printf("\nEnter the number of elements: ");
    int size, target;
    scanf("%d", &size);
    int *array = initArray(size);
    printf("Enter the elemets of the array:\n");
    fillArray(array, size);

    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = linearSearch(array, size, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n\n", target);
    }

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int *initArray(int size){
    int *array = calloc(size, sizeof(int));
    return array;
}

void fillArray(int *array, int size){

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void sortArray(int *array, int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int binarySearch(int *array, int size, int target) {
    sortArray(array,size);
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        }

        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    int result = binarySearch(array, size, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n\n", target);
    }

    return 0;
}
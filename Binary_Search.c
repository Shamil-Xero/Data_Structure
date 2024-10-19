#include<stdio.h>
#include<stdlib.h>

int *initArray(int size){
    int *array = calloc(size, sizeof(int));
    return array;
}

void fillArray(int *array, int size){
<<<<<<< Tabnine <<<<<<<
/**//+
 * @brief Initializes a dynamically allocated array of integers.//+
 *//+
 * This function creates a new array of integers with the specified size,//+
 * initializing all elements to zero using calloc.//+
 *//+
 * @param size The number of elements to allocate in the array.//+
 * @return int* A pointer to the newly allocated and initialized array,//+
 *         or NULL if the allocation fails.//+
 *///+
int *initArray(int size){//+
    int *array = calloc(size, sizeof(int));//+
    return array;//+
}//+
>>>>>>> Tabnine >>>>>>>// {"conversationId":"b2b89f86-7eec-4df4-8fb6-a7f3172529a6","source":"instruct"}
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

int binarySearch(int *array, int size, int target) {
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
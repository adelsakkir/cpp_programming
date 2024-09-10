#include <stdio.h>
#include <stdlib.h>

int main() {
    int *list = NULL;      // Pointer to store the dynamic array
    int size = 0;          // Number of elements currently in the list
    int capacity = 1;      // Initial capacity of the list

    // Allocate initial memory for 1 element
    list = (int *)malloc(capacity * sizeof(int));
    //printf("Size of list %d\n",sizeof(*list));
    if (list == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Example loop to add elements dynamically
    for (int i = 0; i < 10; i++) {
        // Check if the current size has reached the capacity
        if (size == capacity) {
            // Double the capacity
            capacity *= 2;
            // Reallocate memory with the new capacity
            int *temp = realloc(list, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed!\n");
                free(list); // Free the previously allocated memory
                return 1;   // Exit if memory reallocation fails
            }
	    //printf("Memory reallocation successful!\n");
            list = temp; // Update the list pointer to the new block of memory
        }

        // Add an element to the list
        list[size] = i + 1; // Example: adding elements 1, 2, 3, ..., 10
        size++; // Increment the size
    }

    // Print the list elements
    printf("List elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    //printf("Size of list %d\n",sizeof(*list));

    // Free the allocated memory
    free(list);

    return 0;
}

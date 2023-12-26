#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers and store them in an array
void generateRandomNumbers(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand();  // Generate random numbers
    }
}

// Function to perform Insertion Sort
void performInsertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int currentElement = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > currentElement) {
            // Shift elements to the right
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentElement;
    }
}

int main() {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int randomArray[size];
    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers and store them in the array
    generateRandomNumbers(randomArray, size);

    clock_t startTime, endTime;
    double elapsedTime;

    // Start the timer
    startTime = clock();  // O(1)

    // Call the Insertion Sort algorithm to sort the array
    performInsertionSort(randomArray, size);  // O(n^2)

    // Stop the timer
    endTime = clock();  // O(1)

    // Calculate the CPU time used
    elapsedTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;  // O(1)

    printf("Sorted array using Insertion Sort:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", randomArray[i]);
    }
    printf("\n");

    printf("Time taken by Insertion Sort: %f seconds\n", elapsedTime);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
void insertionSort(float array[], int size) {
    for (int i = 1; i < size; i++) {
        float key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}


void bucketSort(float array[], int size) {
    float max = array[0], min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    float range = (max - min) / size + 1;
    float **buckets = (float **)malloc(size * sizeof(float *));
    for (int i = 0; i < size; i++) {
        buckets[i] = NULL;
    }
    for (int i = 0; i < size; i++) {
        int index = (array[i] - min) / range;
        int bucketSize = (buckets[index] == NULL) ? 0 : buckets[index][0];

        buckets[index] = (float *)realloc(buckets[index], (bucketSize + 2) * sizeof(float));
        buckets[index][bucketSize + 1] = array[i];
        buckets[index][0] = bucketSize + 1;
    }
    for (int i = 0; i < size; i++) {
        if (buckets[i] != NULL) {
            insertionSort(buckets[i] + 1, buckets[i][0]);
        }
    }
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (buckets[i] != NULL) {
            for (int j = 1; j <= buckets[i][0]; j++) {
                array[index++] = buckets[i][j];
            }
            free(buckets[i]);
        }
    }
    free(buckets);
}
void printArray(float array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%0.2f ", array[i]);
    }
    printf("\n");
}
int main() {
    float array[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Original array: ");
    printArray(array, size);
    bucketSort(array, size);
    printf("Sorted array: ");
    printArray(array, size);
    return 0;
}

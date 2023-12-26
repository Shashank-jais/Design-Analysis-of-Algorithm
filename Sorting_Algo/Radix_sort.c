#include <stdio.h>
int findMax(int array[], int size) {
    int maxVal = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > maxVal)
            maxVal = array[i];
    return maxVal;
}
void performCountSort(int array[], int size, int exponent) {

    int sortedArray[size];
    int i, count[10] = {0};

    for (i = 0; i < size; i++)
        count[(array[i] / exponent) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--) {
        sortedArray[count[(array[i] / exponent) % 10] - 1] = array[i];
        count[(array[i] / exponent) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sortedArray[i];
}
void performRadixSort(int array[], int size) {

    int maxVal = findMax(array, size);

    for (int exponent = 1; maxVal / exponent > 0; exponent *= 10)
        performCountSort(array, size, exponent);
}

void displayArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int dataArray[n];
    for (int i = 0; i < n; i++) {
        dataArray[i] = getRandomNumber(100, 999); // Generate a random array of elements
    }

    printf("Original array: ");
    displayArray(dataArray, n);

    performRadixSort(dataArray, n);

    printf("Sorted Array: ");
    displayArray(dataArray, n);

    return 0;
}


//ok
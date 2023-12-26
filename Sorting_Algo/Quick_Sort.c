#include <stdio.h>
#include <stdlib.h> // Include this for rand()
#include <time.h>
// Global variable to count comparisons
long long flag = 0;
// Merge two sorted subarrays into one sorted array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    { // Find elements greater than the pivot from the left
        while (arr[i] < pivot)
        {
            flag++;
            i++;
        }
        // Find elements less than the pivot from the right
        while (arr[j] > pivot)
        {
            flag++;
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

// Function to generate a random number between 'min' and 'max'
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Function to print the elements of an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
// Function to perform quicksortF
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);

        // Recursively sort the two halves
        QuickSort(arr, low, index - 1);
        QuickSort(arr, index + 1, high);
    }
}

int main()
{
    int max;
    int arr[] = {10, 80, 30, 90, 40};
    printf("Enter the number of elements : ");
    scanf("%d", &max);
    // int arr[max];
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;
    // for (int i = 0; i < max; i++)
    // {
    //     arr[i] = getRandomNumber(2, 800); // Generate a random array of 10 elements
    // }

    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Print the original array
    printf("Array before sorted: ");
    print(arr, n);
    start = clock(); // O(1)
    // Perform the Quick sort
    QuickSort(arr, 0, n - 1);

    end = clock();                                            // O(1)
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // O(1)

    printf("\n-----------Using Quick Sort ---------------------\n");
    printf("Array After sorted: ");
    print(arr, n);
    printf("\nComparisons made during Quick Sort: %lld\n", flag); // Print the comparison count
    printf("Time taken by Quick Sort: %f seconds\n", cpu_time_used);
    return 0;
}

#include <stdio.h>
#include <stdlib.h> // Include this for rand()
#include <time.h>
// Global variable to count comparisons
long long flag = 0;
// Merge two sorted subarrays into one sorted array
void merge(int arr[], int low, int mid, int high)
{
    int x = 0;
    int ind1 = low;
    int ind2 = mid + 1;
    int merged[high - low + 1];
    // Merge the subarrays
    while (ind1 <= mid && ind2 <= high)
    {
        flag++; // Increment the comparison count
        if (arr[ind1] <= arr[ind2])
        {
            merged[x++] = arr[ind1++];
        }
        else
        {
            merged[x++] = arr[ind2++];
        }
    }
    // Copy any remaining elements from the subarrays
    while (ind1 <= mid)
    {
        merged[x++] = arr[ind1++];
    }
    while (ind2 <= high)
    {
        merged[x++] = arr[ind2++];
    }
    int k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = merged[k++];
    }
}

// Recursively divide and merge the array to sort it
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        // Recursively sort the two halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
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

int main()
{
    int max;
    printf("Enter the number of elements : ");
    scanf("%d", &max);
    int arr[max];
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < max; i++)
    {
        arr[i] = getRandomNumber(2, 800); // Generate a random array of 10 elements
    }

    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Print the original array
    printf("Array before sorted: ");
    print(arr, n);
    start = clock(); // O(1)
    // Perform the merge sort
    mergeSort(arr, 0, n - 1);

    end = clock();                                            // O(1)
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // O(1)

    printf("\n-----------Using Merge Sort ---------------------\n");
    printf("Array After sorted: ");
    print(arr, n);
    printf("\nComparisons made during Merge Sort: %lld\n", flag); // Print the comparison count
    printf("Time taken by Merge Sort: %f seconds\n", cpu_time_used);
    return 0;
}

//okk 
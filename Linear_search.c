#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Include this for rand()

int linearSearch(int arr[], int n, int target)
{
    long flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag++;
        if (arr[i] == target)
        {
            flag++;
            printf("Linear Search Time: %ld\n", flag);
            return i + 1;
        }
    }
    return -1; // Element not found
}

int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = getRandomNumber(1, 20);
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 19;
    print(arr, n);
    printf("\nTarget element %d \n", target);
    printf("Binary Search\n");
    int result = linearSearch(arr, n, target);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result);

    return 0;
}


//okk
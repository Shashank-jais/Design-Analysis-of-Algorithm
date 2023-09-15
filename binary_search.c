#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // Include this for rand()

int binarySearch(int arr[], int left, int right, int target)
{
    int flag = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        

        if (arr[mid] == target)
        {
            flag++;

            printf("Binary Search time: %d\n", flag);
            return mid;
        }

        if (arr[mid] < target)
        {
            flag++;
            left = mid + 1;
        }
        else
        {
            flag++;
            right = mid - 1;
        }
    }
    return -1;
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
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result + 1);


    return 0;
}



//0kk
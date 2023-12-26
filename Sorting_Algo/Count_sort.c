#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void count_sort(int *A, int n)
{
    int i, j;
    int max = maximum(A, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (j = 0; j < n; j++)
    {
        count[A[j]] = count[A[j]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = getRandomNumber(100, 998);
    }

    printf("Original array: ");
    printArray(A, n);
    count_sort(A, n);
    printf("Sorted Array: ");
    printArray(A, n);
    return 0;
}

// ok
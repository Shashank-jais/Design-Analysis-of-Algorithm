#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int c=0;
void print(int x[], int n)
{
    printf("Solution: %d\n", c);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x[i] == j)
            {
                printf(" Q ");
            }
            else
            {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}
bool place(int k, int i, int x[])
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}
void Nqueen(int k, int n, int x[])
{
    if (k == n)
    {
        c++;
        print(x, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (place(k, i, x))
        {
            x[k] = i;
            Nqueen(k + 1, n, x);
        }
    }
}
int main()
{
    int n;
    static int count = 0;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    int result[n];
    Nqueen(0, n, result);
    return 0;
}

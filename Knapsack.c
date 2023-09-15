#include <stdio.h>

void greedy(int p[], int w[], int n, int m)
{
    float pw[n];
    float pro = 0.0;

    for (int i = 0; i < n; i++)
    {
        pw[i] = (float)p[i] / w[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pw[j] < pw[j + 1])
            {
                float t = pw[j];
                pw[j] = pw[j + 1];
                pw[j + 1] = t;

                int k = p[j];
                p[j] = p[j + 1];
                p[j + 1] = k;

                int l = w[j];
                w[j] = w[j + 1];
                w[j + 1] = l;
            }
        }
    }

    printf("\nItems Supplied in a bag\n");

    printf("\nItem\tWeight\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        if (m >= w[i])
        {
            printf("%d\t%d\t%d\n", i + 1, w[i], p[i]);
            m -= w[i];
            pro += p[i];
        }
        else
        {
            printf("%d\t%d\t%d\n", i + 1, m, p[i]);
            pro += (m * pw[i]);
            break;
        }
    }
    printf("\nTotal Profit: %.2f\n", pro);
}

void inputValues(int *n, int *w, int profit[], int weight[])
{
    printf("Enter the number of items (n): ");
    scanf("%d", n);

    printf("Enter the maximum weight capacity (w): ");
    scanf("%d", w);

    for (int i = 0; i < *n; i++)
    {
        printf("Enter the profits for %d items: ", i + 1);
        scanf("%d", &profit[i]);
        printf("Enter the weights for %d items: ", i + 1);
        scanf("%d", &weight[i]);
    }
}

int main()
{
    int n, w;
    int profit[100], weight[100];

    inputValues(&n, &w, profit, weight);
    printf("\nItems available to be supplied in a bag\n");
    printf("\nItem\tWeight\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, weight[i], profit[i]);
    }
    greedy(profit, weight, n, w);

    return 0;
}



//okk
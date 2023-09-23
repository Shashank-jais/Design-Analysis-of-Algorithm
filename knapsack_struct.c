// knapsack implemented by structure and with sorting

#include <stdio.h>
#include <stdlib.h>

struct knapsack
{
    int id;     // product identifier
    int profit; // product profit
    int weight; // product weight
    float pw;   // product profitper weight
};
void inputValues(int *n, int *w, struct knapsack objects[])                       // input values of the product ie profit and weight
{
    printf("Enter the number of items (n): ");
    scanf("%d", n);//no of items

    printf("Enter the maximum weight capacity (w): ");
    scanf("%d", w);   //maximum weight capacity

    for (int i = 0; i < *n; i++)
    {
        printf("Enter the profits for %d items: ", i + 1);
        scanf("%d", &objects[i].profit);              //profit of ith item
        printf("Enter the weights for %d items: ", i + 1);
        scanf("%d", &objects[i].weight);             //weight of i th item
        objects[i].id = i + 1;
    }
}

void printValues(int n, int w, struct knapsack objects[])       
{
    printf("\nItems available to be supplied in a bag\n");
    printf("\nItem\tWeight\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", objects[i].id, objects[i].weight, objects[i].profit);
    }
}
void greedy_method(int n, int m, struct knapsack objects[])
{
    float profit = 0;
    int weight = 0;

    for (int i = 0; i < n; i++)
    {
        objects[i].pw = (float)objects[i].profit / objects[i].weight;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (objects[j].pw < objects[j + 1].pw)
            {
                struct knapsack temp = objects[j];
                objects[j] = objects[j + 1];
                objects[j + 1] = temp;
            }
        }
    }

    printf("\nItems Supplied in a bag\n");

    printf("\nItem\tWeight\tProfit\n");
    for (int i = 0; i < n; i++)
    {
        if (m >= objects[i].weight)
        {
            printf("%d\t%d\t%d\n", objects[i].id, objects[i].weight, objects[i].profit);
            m -= objects[i].weight;
            profit += objects[i].profit;
        }
        else
        {
            printf("%d\t%d\t%d\n", objects[i].id, m, objects[i].profit);
            profit += (m * objects[i].pw);
            break;
        }
    }
    printf("\nTotal Profit: %.2f\n", profit);
}
int main()
{
    struct knapsack objects[100];
    int n, m;
    inputValues(&n, &m, objects);
    printValues(n, m, objects);
    printf("----------------------------------------------------------------");
    greedy_method(n, m, objects);
}

// Enter the number of items (n): 7
// Enter the maximum weight capacity (w): 15
// Enter the profits for 1 items: 10
// Enter the weights for 1 items: 2
// Enter the profits for 2 items: 5
// Enter the weights for 2 items: 3
// Enter the profits for 3 items: 15
// Enter the weights for 3 items: 5
// Enter the profits for 4 items: 7
// Enter the weights for 4 items: 7
// Enter the profits for 5 items: 6
// Enter the weights for 5 items: 1
// Enter the profits for 6 items: 18
// Enter the weights for 6 items: 4
// Enter the profits for 7 items: 3
// Enter the weights for 7 items: 1

// Items available to be supplied in a bag

// Item    Weight  Profit
// 1       2       10
// 2       3       5
// 3       5       15
// 4       7       7
// 5       1       6
// 6       4       18
// 7       1       3
// ----------------------------------------------------------------
// Items Supplied in a bag

// Item    Weight  Profit
// 5       1       6
// 1       2       10
// 6       4       18
// 3       5       15
// 7       1       3
// 2       2       5

// Total Profit: 55.33


//okk
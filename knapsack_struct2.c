// knapsack implemented by structure and without sorting

#include <stdio.h>
#include <stdlib.h>

struct knapsack
{
    int id;     // product identifier
    int profit; // product profit
    int weight; // product weight
    float pw;   // product profit per weight
};

void inputValues(int *n, int *w, struct knapsack objects[])
{
    printf("Enter the number of items (n): ");
    scanf("%d", n);

    printf("Enter the maximum weight capacity (w): ");
    scanf("%d", w);

    for (int i = 0; i < *n; i++)
    {
        printf("Enter the profits for item %d: ", i + 1);
        scanf("%d", &objects[i].profit);
        printf("Enter the weight for item %d: ", i + 1);
        scanf("%d", &objects[i].weight);
        objects[i].id = i + 1;
        objects[i].pw = (float)objects[i].profit / objects[i].weight;
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

void greedyKnapsack(int n, int m, struct knapsack objects[])
{
    float profit = 0;
    int weight = 0;
    int mm = m;

    printf("\nItems Supplied in a bag\n");
    printf("\nItem\tWeight\tProfit\n");

    while (m > 0)
    {
        int selected_item = -1;
        float max_pw = 0;

        for (int i = 0; i < n; i++)
        {
            if (objects[i].weight > 0 && objects[i].pw > max_pw)
            {
                selected_item = i;
                max_pw = objects[i].pw;
            }
        }

        if (selected_item == -1)
        {
            break;
        }

        if (m >= objects[selected_item].weight)
        {
            printf("%d\t%d\t%d\n", objects[selected_item].id, objects[selected_item].weight, objects[selected_item].profit);
            m -= objects[selected_item].weight;
            profit += objects[selected_item].profit;

            objects[selected_item].weight = 0;
            objects[selected_item].pw = 0;
        }
        else
        {
            printf("%d\t%d\t%d\n", objects[selected_item].id, m, objects[selected_item].profit);
            profit += (m * objects[selected_item].pw);

            objects[selected_item].weight -= m;
            objects[selected_item].pw = objects[selected_item].profit / objects[selected_item].weight;
            break;
        }
    }

    printf("\nTotal Profit: %.2f\n", profit);
    printf("----------------------------------------------------------------");
    printf("----------------------------------------------------------------");
    printValues(n, mm, objects);
}

int main()
{
    struct knapsack objects[100];
    int n, m;
    inputValues(&n, &m, objects);
    printValues(n, m, objects);
    printf("----------------------------------------------------------------");
    greedyKnapsack(n, m, objects);

    return 0;
}


//INPUT
// Enter the number of items (n): 7
// Enter the maximum weight capacity (w): 15
// Enter the profits for item 1: 10
// Enter the weight for item 1: 2
// Enter the profits for item 2: 5
// Enter the weight for item 2: 3
// Enter the profits for item 3: 15
// Enter the weight for item 3: 5
// Enter the profits for item 4: 7
// Enter the weight for item 4: 7
// Enter the profits for item 5: 6
// Enter the weight for item 5: 1
// Enter the profits for item 6: 18
// Enter the weight for item 6: 4
// Enter the profits for item 7: 3
// Enter the weight for item 7: 1


//OUTPUT
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
// --------------------------------------------------------------------------------------------------------------------------------
// Items available to be supplied in a bag

// Item    Weight  Profit
// 1       0       10
// 2       1       5
// 3       0       15
// 4       7       7
// 5       0       6
// 6       0       18
// 7       0       3
// PS D:\C LANGUAGE\DAA>

//okk 
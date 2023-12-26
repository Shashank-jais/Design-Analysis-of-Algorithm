#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int vertice;
    struct node *next;
};

struct Graph
{
    int no_vertices;
    struct node **Adj_list;
};
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->no_vertices = vertices;

    graph->Adj_list = (struct node **)malloc(vertices * sizeof(struct node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->Adj_list[i] = NULL;
    }
    return graph;
}
struct node *newnode(int vertice)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->vertice = vertice;
    new_node->next = NULL;
    return new_node;
}
void addnode_undir(struct Graph *graph, int src, int dest)
{
    struct node *new_node = newnode(dest);
    new_node->next = graph->Adj_list[src];
    graph->Adj_list[src] = new_node;

    new_node = newnode(src);
    new_node->next = graph->Adj_list[dest];
    graph->Adj_list[dest] = new_node;
}

void printSolution(int color[], int max)
{
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < max; i++)
        printf("%d:%d\n", i + 1, color[i]);
    printf("\n");
}
bool isSafe(int v, struct Graph *graph, int color[], int c)
{
    struct node *temp = graph->Adj_list[v];

    while (temp)
    {
        if (c == color[temp->vertice])
            return false;
        temp = temp->next;
    }
    return true;
}
bool graphcolor(struct Graph *graph, int color[], int m, int v, int max)
{
    if (v == max)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphcolor(graph, color, m, v + 1, max) == true)
            {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}
bool graphcoloring(struct Graph *graph, int m, int max)
{
    int color[max];
    for (int i = 0; i < max; i++)
        color[i] = 0;

    if (graphcolor(graph, color, m, 0, max) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    printSolution(color, max);
    return true;
}

void printGraph(struct Graph *graph)
{
    printf("Graph Visualization:\n");
    printf("   ");
    for (int v = 0; v < graph->no_vertices; v++)
    {
        printf("%d  ", v);
    }
    printf("\n");
    for (int v = 0; v < graph->no_vertices; v++)
    {
        printf("%d: ", v);
        for (int u = 0; u < graph->no_vertices; u++)
        {
            struct node *temp = graph->Adj_list[v];
            int connected = 0;

            while (temp)
            {
                if (temp->vertice == u)
                {
                    connected = 1;
                    break;
                }
                temp = temp->next;
            }

            if (connected)
            {
                printf("1  ");
            }
            else
            {
                printf("0  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int max, src, dest, flag, choices, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &max);
    struct Graph *graph = createGraph(max);
    printf("Undirected graph\n");
    do
    {
        printf("Enter the Source node: ");
        scanf("%d", &src);
        printf("Enter the Destination node: ");
        scanf("%d", &dest);
        addnode_undir(graph, src, dest);
        printf("Want to add mode connection between node: (1 for yes OR 0 for no):       ");
        scanf("%d", &flag);
        if (flag == 0)
        {
            break;
        }
    } while (true);
    printGraph(graph);
    printf("Enter the No of color: ");
    scanf("%d", &m);
    graphcoloring(graph, m, max);
}

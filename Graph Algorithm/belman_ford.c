#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int vertice;
    int weight;
    struct Node *next;
};
struct Graph
{
    int no_vertices;
    struct Node **Adj;
};

struct Graph *create_graph(int no__vertex)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->no_vertices = no__vertex;
    graph->Adj = (struct Node **)malloc(no__vertex * sizeof(struct Node *));
    for (int i = 0; i < no__vertex; i++)
    {
        graph->Adj[i] = NULL;
    }
    return graph;
}
struct Node *New_node(int vertex)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->vertice = vertex;
    node->weight = 0;
    node->next = NULL;
    return node;
}

void add_node_undir(struct Graph *graph, int src, int dest)
{
    int d;
    struct Node *new_node = New_node(dest);
    printf("Enter the distance between from %d to %d : ", src, dest);
    scanf("%d", &d);
    new_node->weight = d;
    new_node->next = graph->Adj[src];
    graph->Adj[src] = new_node;

    // new_node = New_node(src);
    // printf("Enter the distance between from %d to %d : ", dest, src);
    // scanf("%d", &d);
    // new_node->weight = d;
    // new_node->next = graph->Adj[dest];
    // graph->Adj[dest] = new_node;
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
            struct Node *temp = graph->Adj[v];
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
                printf("%d  ", temp->weight);
            }
            else
            {
                printf("0  ");
            }
        }
        printf("\n");
    }
}
void Bellman_ford(struct Graph *graph, int src)
{
    int dist[graph->no_vertices];
    bool visit[graph->no_vertices];
    for (int i = 0; i < graph->no_vertices; i++)
    {
        dist[i] = INT32_MAX;
        visit[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < graph->no_vertices - 1; i++)
    {
        for (int j = 0; j < graph->no_vertices; j++)
        {
           
            struct Node *temp = graph->Adj[j];
            while (temp)
            {
                if  (dist[j] + temp->weight < dist[temp->vertice])
                {
                    dist[temp->vertice] = dist[j] + temp->weight;
                }
                temp = temp->next;
            }
        }
    }
    for(int i = 0; i < graph->no_vertices; i++){
        printf("\n\n\n");
        printf("%d\n",dist[i]);
    }
    for (int j = 0; j < graph->no_vertices; j++)
        {
           
            struct Node *temp = graph->Adj[j];
            while (temp)
            {
                if(dist[j] + temp->weight < dist[temp->vertice])
                {
                    printf("Negative weight cycle");
                    exit(1);
                }
                temp = temp->next;
            }
        }
}
int main()
{

    int max, src, dest, flag, choices;
    printf("Enter the number of vertices: ");
    scanf("%d", &max);
    struct Graph *graph = create_graph(max);
    do
    {
        printf("Enter the Source node: ");
        scanf("%d", &src);
        printf("Enter the Destination node: ");
        scanf("%d", &dest);
        add_node_undir(graph, src, dest);
        printf("Want to add mode connection between node: (1 for yes OR 0 for no):       ");
        scanf("%d", &flag);
        if (flag == 0)
        {
            break;
        }

    } while (true);
    printGraph(graph);
    Bellman_ford(graph,0);
    return 0;
}
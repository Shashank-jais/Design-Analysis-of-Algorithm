#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
struct node
{
    int vertice;
    struct node *next;
    int distance;
    bool visit;
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
    new_node->distance = 0;
    new_node->visit = false;
    return new_node;
}
void addnode_undir(struct Graph *graph, int src, int dest)
{
    int d;
    struct node *new_node = newnode(dest);
    printf("Enter the distance between from %d to %d : ", src, dest);
    scanf("%d", &d);
    new_node->distance = d;
    new_node->next = graph->Adj_list[src];
    graph->Adj_list[src] = new_node;

    new_node = newnode(src);
    printf("Enter the distance between from %d to %d : ", dest, src);
    scanf("%d", &d);
    new_node->distance = d;
    new_node->next = graph->Adj_list[dest];
    graph->Adj_list[dest] = new_node;
}
void addnode_dir(struct Graph *graph, int src, int dest)
{
    int d;
    struct node *new_node = newnode(dest);
    printf("Enter the distance between from %d to %d : ", src, dest);
    scanf("%d", &d);
    new_node->distance = d;
    new_node->next = graph->Adj_list[src];
    graph->Adj_list[src] = new_node;
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
                printf("%d  ", temp->distance);
            }
            else
            {
                printf("0  ");
            }
        }
        printf("\n");
    }
}

int min_dist(int dist[], struct Graph *graph, bool visit[] )
{
    int min = INT32_MAX;
    int ind;
    for (int i = 0; i < graph->no_vertices; i++){
        if(visit[i]==false && dist[i] < min){
          min=dist[i];
          ind=i;
        }
    }
    return ind;
}
void dijkstra_algo(struct Graph *graph, int src)
{
    int dist[graph->no_vertices];
    bool visit[graph->no_vertices];
    for (int i = 0; i < graph->no_vertices; i++)
    {
        dist[i] = INT32_MAX;
        visit[i]=false;
    }
    dist[src] = 0;
    for (int i = 0; i < graph->no_vertices; i++)
    {
        int m =min_dist(dist,graph,visit);
        visit[m]=true;
        struct node *temp = graph->Adj_list[m];
        while(temp){
            if(!visit[temp->vertice] && (dist[m]+temp->distance<dist[temp->vertice])){
                dist[temp->vertice] = dist[m]+temp->distance;
            }
            temp = temp->next;
        }

    }
    for(int i = 0; i < graph->no_vertices; i++){
        printf("\n\n\n");
        printf("%d\n",dist[i]);
    }
}

int main()
{

    int max, src, dest, flag, choices;
    printf("Enter the number of vertices: ");
    scanf("%d", &max);
    struct Graph *graph = createGraph(max);
    printf("Enter the types of graph: \n");
    printf("1. Directed graph\n");
    printf("2. Undirected graph\n");
    scanf("%d", &choices);
    switch (choices)
    {
    case 1:
        do
        {
            printf("Enter the Source node: ");
            scanf("%d", &src);
            printf("Enter the Destination node: ");
            scanf("%d", &dest);
            addnode_dir(graph, src, dest);
            printf("Want to add mode connection between node: (1 for yes OR 0 for no):       ");
            scanf("%d", &flag);
            if (flag == 0)
            {
                break;
            }

        } while (true);
        printGraph(graph);
        dijkstra_algo(graph,0);
        break;
    case 2:
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
        dijkstra_algo(graph,0);
        break;
    default:
        printf("Wrong input");
    }
}

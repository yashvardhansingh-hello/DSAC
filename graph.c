#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_VERTICES 50

typedef struct Graph_t{
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
}Graph;

Graph* createGraph(int V){
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            g->adj[i][j] = false;
        }
    }
    return g;
}

void destroyGraph(Graph* g){
    free(g);
}

void addEdge(Graph* g, int v, int w){
    g->adj[v][w] = true;
}

//Prints BFS traversal from a given source s
void BFS(Graph* g, int s){

    //Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;
    
    while (front != rear)
    {
        // Dequeue a vertex form queue and print it
        s = queue[front++];
        printf("%d ", s);

        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjacent = 0; adjacent < g->V; adjacent++)
        {
            if (g->adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

// Print DFS traversal from a given source s
bool reach[MAX_VERTICES];
void DFS(Graph* g, int s){
    reach[s] = true;
    printf("%d ", s);
    for (int i = 0; i < g->V; i++)
    {
        if (g->adj[g->V][i] && !reach[i])
        {
            DFS(g, i);
        }
        
    }
    
    
}

void main(){
    Graph* g = createGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 0, 1);
    addEdge(g, 3, 3);

    printf("Following is the Breadth First Traversal "
    "(starting form vertex 2)\n");
    DFS(g, 2);
    destroyGraph(g);
}
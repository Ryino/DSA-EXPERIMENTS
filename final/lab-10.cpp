#include <iostream>
using namespace std;

struct adjlistnode
{
    int data;
    adjlistnode *next;
};

struct adjlist
{
    adjlistnode *head;
};

struct Graph
{
    int v;
    adjlist *arr;
};

adjlistnode *newadjlistnode(int data)
{
    adjlistnode *n = new adjlistnode;
    n->data = data;
    n->next = NULL;
    return n;
}

Graph *createGraph(int v)
{
    Graph *g = new Graph;
    g->v = v;
    g->arr = new adjlist[v];
    for (size_t i = 0; i < v; i++)
    {
        g->arr[i].head = NULL;
    }
    return g;
}

void addedge(Graph *g, int src, int dest)
{
    adjlistnode *n = newadjlistnode(dest);
    n->next = g->arr[src].head;
    g->arr[src].head = n;
    n = newadjlistnode(src);
    n->next = g->arr[dest].head;
    g->arr[dest].head = n;
}

// function to print the graph
void printGraph(Graph *graph)
{
    // loop over each adjacent list
    for (int i = 0; i < graph->v; i++)
    {
        adjlistnode *root = graph->arr[i].head;
        cout << "Adjacency list of vertex " << i << endl;
        // loop over each node in list
        while (root != NULL)
        {
            cout << root->data << " -> ";
            root = root->next;
        }
        cout << endl;
    }
}

int main()
{
    // create a new graph
    int totalVertices = 4;
    Graph *graph;
    graph = createGraph(totalVertices);
    // connect edges
    addedge(graph, 0, 1);
    addedge(graph, 0, 2);
    addedge(graph, 0, 3);
    addedge(graph, 1, 3);
    addedge(graph, 2, 3);
    /*
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    */
    // print the adjacency list representation of graph
    printGraph(graph);
}

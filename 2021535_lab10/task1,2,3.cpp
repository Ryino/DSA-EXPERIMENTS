#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;

    list<int> *adj;

    void printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index, int num)
    {

        visited[v1] = true;
        path[index] = v1;
        index++;

        if (v1 == v2)
        {
            int i;
            if (!pathExist)
                cout << "Following are the paths between " << path[0] << " and " << path[index - 1] << endl;
            pathExist = true;
            for (i = 0; i < index - 1; i++)
                cout << path[i] << "->";
            cout << path[i] << endl;
        }
        else
        {

            list<int>::iterator i;
            for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
                if (!visited[*i])
                    printAllPathsUtil(*i, v2, visited, path, index, num++);
        }

        index--;
        visited[v1] = false;
    }

    void DFSUtil(int v, bool visited[])
    {

        visited[v] = true;
        visitedNodes++;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }

public:
    Graph(int V);
    bool pathExist;

    void addEdge(int v, int w);
    void printAllPaths(int v1, int v2, int paths);
    int visitedNodes;
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}


void Graph::printAllPaths(int v1, int v2, int paths)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    int *path = new int[V];

    int index = 0;

    pathExist = false;

    int num;

    printAllPathsUtil(v1, v2, visited, path, index, num);
}



void Graph::DFS(int v)
{

    visitedNodes = 0;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}

int main()
{

    Graph g(6);

    int i;

    int a[] = {0, 1, 2, 3, 4, 5};

    g.addEdge(0, 1);
    g.addEdge(5, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(0, 2);

    int n = sizeof(a) / sizeof(a[0]);
    int paths = 2;
    for (i = 0; i < n; i++)
    {
        g.DFS(a[i]);

        if (g.visitedNodes == n)
            break;
    }
    if (i == n)
        cout << "There is no mother vertex in this graph";
    else
        cout << "Mother vertex of this graph is " << a[i];

    cout << "\n\n";

    int v1 = 0, v2 = 2;

    g.printAllPaths(v1, v2, paths);

    cout << "The number of paths are " << paths << endl;

    if (!g.pathExist)
    {
        cout << "There is no path  between " << v1 << " and " << v2 << " : ";
    }
}
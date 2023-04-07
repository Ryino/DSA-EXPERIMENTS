#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;

public:
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }

    void addedge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void dfsutil(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";

        list<int>::iterator i;

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                dfsutil(*i, visited);
            }
        }
    }

    void dfs(int v)
    {
        bool *visited = new bool[v];

        for (size_t i = 0; i < v; i++)
        {
            visited[i] = false;
        }
        dfsutil(v, visited);
    }
    int count_paths(int src, int dst, int vertices)
    {
        int path_count = 0;
        vector<bool> visited(vertices, false);
        path_counter(src, dst, path_count, visited);
        return path_count;
    }
    void path_counter(int src, int dst, int &path_count, vector<bool> &visited)

    {

        visited[src] = true;
        if (src == dst)
        {
            path_count++;
        }

        else
        {
            for (auto neighbour : adj[src])
            {
                if (!visited[neighbour])
                    path_counter(neighbour, dst, path_count,
                                 visited);
            }
        }
        visited[src] = false;
    }
    
};
int main()
{
    // Create a graph given in the above diagram - see link
    Graph g(5);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(0, 4);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 3);
    g.addedge(2, 1);
    g.addedge(3, 2);
     cout<<"DFS display(task 3):\n";
    g.dfs(0);  
    cout<<"\nNumber of paths between 0 and 4:(task 1) ";
    cout << g.count_paths(0, 4, 5);
 
    return 0;
}
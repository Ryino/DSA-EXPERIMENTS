#include <iostream>
#include <list>

using namespace std;

class graph
{
    bool *visited;
    list<int> *l;

public:
    int v;
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void add_edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "vertex: " << i << "->";
            for (int nei : l[i])
            {
                cout << nei << " ";
            }
            cout << endl;
        }
    }

    void bfs(int sv)
    {
        visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        list<int> q;
        visited[sv] = true;
        q.push_back(sv);
        list<int>::iterator i;
        while (!q.empty())
        {
            int curr = q.front();
            cout << "visited :" << curr << " ";
            q.pop_front();

            for (i = l[curr].begin(); i != l[curr].end(); i++)

            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push_back(*i);
                }
            }
        }
    }
    void dfs(int sv)
    {
        
       
        // preorder
        visited[sv] = true;
        cout << sv << ",";

        // inorder
        list<int>::iterator i;

        for (i=l[sv].begin();i!=l[sv].end();i++)
        {
            if(!visited[*i])
            {
                dfs(*i);
            }
        }
    }
};

int main()
{
    graph g(4);
    g.add_edge(9, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
    // g.bfs(0);
    g.dfs(0);
    // g.print();
}
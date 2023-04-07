// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;

class graph
{
public:
    int v;
    list<int> *l;
    bool *visited;

    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addedge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertix:" << i << "->";
            for (int nei : l[i])
            {
                cout << nei << ",";
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
            cout<<"Visited :"<< curr<<" ";
            q.pop_front();

            for(i=l[curr].begin();i!=l[curr].end();i++)
            { curr= *i;
                if(!visited[curr])
                {  
                    visited[curr]=true;
                    q.push_back(curr);
                }
            }
        }
        

    }
};

int main()
{
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    g.print();
    // g.bfs(0);

    return 0;
}
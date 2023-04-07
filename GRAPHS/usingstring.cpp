#include<iostream>
#include<list>
using namespace std;

class graph
{
    int v;
    bool *visited;
    list <string> *l;
    public:
    graph(int v )
    {
        this->v=v;
        l= new list<string>[v];
        
    }

    void add_edge(string x , string y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"Vertex :"<<i<<" ->";
            for(string nei:l[i])
            {
                cout<<nei;
            }
        }
    }

    void dfs(int sc)
    {
        //preorder 
        visited[sv]=true ;
        cout<<"Vertex: "<< v;

        //inorder 

        list<int>::iterator i;

        for(l[])
        {
            if
        }


    }
}

int main()
{

graph g(2);

 g.add_edge("a", "b");
  
    g.print();
}
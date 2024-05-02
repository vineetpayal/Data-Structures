#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // create edge from u to v;
        // direction = false = undirected
        // direction = true = directed;
        adj[u].push_back(v);

        if (direction == false)
        {
            // undirected graph
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"enter number of nodes: ";
    cin>>n;

    int m;
    cout<<"enter number of edges: ";
    cin>>m;

    graph g;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;

        //undirected graph = false
        //directed graph = true;
        g.addEdge(u,v,false);
    }

    g.printAdjList();
}
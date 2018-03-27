// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
using namespace std;
class Graph()
{
    int V;
    list<int>*adj;   // An array of adjacency lists
    void fillOrder(int v, bool visited[], stack<int>&Stack);
    void DFSUtill(int v,bool visited[]);



public :
    Graph(int V)
    void addEdge(int v,int w);
    void printSCCs();
    Graph getTraspose();

};



Graph:: Graph(int V)
{
    this->V=V;
    list<int>*adj;
    adj= new list<int>[V];
}



void Graph::DFSUtil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";

    list<int>::iterator i;

    for(i=adj[v].begin(); i!=adj[v].end();++i)
    {
        if(!visited[*i])
            DFSUtil(*i,visited);
    }
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

Graph Graph::getTranspose()
{
    Graph g(V);
}




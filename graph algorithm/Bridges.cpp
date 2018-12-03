#include<bits/stdc++.h>
using namespace std;
void addEdges(vector<int>adj[],int u ,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);     //undirected graph
}
void bridges(vector<int>adj[],int u, int disc[],int low[], bool visited[], int parent[])
{
    //keep track of discovery time of each vertex
    static int time=0;

    visited[u]=true;    //mark them as visited

    //find discovery point and low
    disc[u]=low[u]=++time;  //because from u we can to u itself thats why both are same
    //go for DFS spanning tree
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();++it)
    {
        int v=*it;
        if(!visited[v])
        {
            parent[v]=u;

            bridges(adj,v,disc,low,visited,parent);

            //subtree rooted with v has a back edge with ancestor of u
            low[u]=min(low[u],low[v]);




            if(low[v]>disc[u])
                cout<<u<<" "<<v<<endl;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
void callingBridges(vector<int>adj[],int n)
{
    int disc[n],parent[n],low[n],i;
    bool visited[n];
    //initializing array
    for(i=0;i<n;i++)
    {
        parent[i]=-1;
        visited[i]=false;

    }
    //calling bridges function for each vertex
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            bridges(adj,i,disc,low,visited,parent);
    }

}
int main()
{
    int n,e,a,b;
    cout<<"\nEnter no.of nodes and edges: ";
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b;
        addEdges(adj, a, b);
    }

    callingBridges(adj,n);
}


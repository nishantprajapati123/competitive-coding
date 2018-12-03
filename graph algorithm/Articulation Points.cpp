#include<bits/stdc++.h>
using namespace std;
void addEdges(vector<int>adj[],int u ,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);     //undirected graph
}
void AP(vector<int>adj[],int u, int disc[],int low[], bool visited[], bool ap[], int parent[])
{
    //keep track of discovery time of each vertex
    static int time=0;

    visited[u]=true;    //mark them as visited
    int children=0;     //count children for each function call
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
            children++; //count children
            AP(adj,v,disc,low,visited,ap,parent);

            //subtree rooted with v has a back edge with ancestor of u
            low[u]=min(low[u],low[v]);

            //check root is AP or not
            if(parent[u]==-1 && children>1)
                ap[u]=true;

            //if u is not root
            if(parent[u]!=-1 && low[v]>=disc[u])
                ap[u]=true;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
void callingAP(vector<int>adj[],int n)
{
    int disc[n],parent[n],low[n],i;
    bool visited[n],ap[n];
    //initializing array
    for(i=0;i<n;i++)
    {
        parent[i]=-1;
        visited[i]=false;
        ap[i]=false;
    }
    //calling AP function for each vertex
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            AP(adj,i,disc,low,visited,ap,parent);
    }
    //all A point is in array ap
    for(i=0;i<n;i++)
    {
        if(ap[i])
            cout<<i<<" ";
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

    callingAP(adj,n);
}

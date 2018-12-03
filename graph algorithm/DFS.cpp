//Undirected graph
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);    //for directed graph don't write 2nd part
    //adj[v].push_back(u);
}
void DFS(int u,vector<int>adj[],vector<bool> &V)
{
    V[u]=true;      //make it visited
    cout<<u<<" ";   //print
    //go for adjacent of this node depth wise
    //i.e., call recursively this function under
    //each child of this node
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();++it)
    {
        if(!V[*it])
            DFS(*it,adj,V);
    }

}
int main()
{
    int n,e,a,b;
    cout<<"\nEnter no.of nodes and edges: ";
    cin>>n>>e;
    vector<bool>V(n,false);
    vector<int>adj[n];
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b;
        addEdge(adj, a, b);
    }
    int t;
    cout<<"\nEnter node where you want to start traversing";
    cin>>t;
	DFS(t,adj,V);
}

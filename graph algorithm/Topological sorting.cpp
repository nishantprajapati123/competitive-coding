#include<bits/stdc++.h>
using namespace std;
void addEdges(vector<int>adj[],int u, int v)
{
    adj[u].push_back(v);    //add edges
}
void topologicalSort(int node,vector<bool>&v, stack<int>&st ,vector<int>adj[])
{
    //make node as visited
    v[node]=true;
    //check for all children not if it is not visited go on its children node
    //if all children not is visited push it into stack
    vector<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();++it)
    {
        if(!v[*it])
            topologicalSort(*it,v,st,adj);

    }
     st.push(node);

         //push into stack
}
void callingTopoSort(int n,vector<int>adj[])
{
    stack<int>st;
    vector<bool>v(n,false);     //Initializing all vertex to be unvisited
    for(int i=0;i<n;i++)        //calling topological sort for each vertex
    {
        if(!v[i])
            topologicalSort(i,v,st,adj);
    }
    cout<<"\nTopological sort: ";
    while(!st.empty())      //print stack
    {
        cout<<st.top()<<" ";
        st.pop();
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

    callingTopoSort(n,adj);
    cout<<"\n"<<k;
}


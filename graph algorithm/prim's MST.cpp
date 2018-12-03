//undirected graph
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void primMST(vector<pair<int,int> >adj[],int src,int n)
{
    int s=0;
    //make priority queue
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int>key(n,INF);
    vector<int>parent(n,-1);
    vector<bool>inMST(n,false);//MST set

    //add source vertex to pq with key=0
    pq.push(make_pair(0,src));
    key[src]=0;    //key of src is 0
    inMST[src]=true;        //add src in mst set
    while(!pq.empty())
    {
        int u;
        u=pq.top().second;    //extract minimum
        pq.pop();               //remove from pq
        inMST[u]=true;          //add in MST
        //for every adjacent child of u
        vector<pair<int,int> >::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();++i)
        {
            int v=(*i).first;     //extract vertex
            int weight=(*i).second;  //extract weight
            if(inMST[v]==false && key[v]>weight)
            {
                //update key value and add v to pq
                key[v]=weight;
                pq.push(make_pair(key[v],v));
                parent[v]=u;
            }
        }
    }
    //cout<<"Edge in MST \nparent\tchild\n";
   // for(int j=1;j<n;j++)
      //  cout<<parent[j]<<"\t"<<j<<endl;
    for(int i=0;i<n;i++)
        s+=key[i];
    cout<<s;
}
int main()
{
    int n,e,a,b,w;
    cout<<"Enter no. of node and edges";
    cin>>n>>e;
    vector<pair<int,int> >adj[n];
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b>>w;
        addEdge(adj,a,b,w);
    }
    cout<<"\nEnter vertex no. where you want to find minimum spanning tree:";
    int t;
    cin>>t;
    primMST(adj,t,n);
}


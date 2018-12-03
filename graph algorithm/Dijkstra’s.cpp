//using priority_queue
#include<bits/stdc++.h>
#include<utility>
#define INF 0x3f3f3f3f
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));   //adding pair wise node and its weight
    adj[v].push_back(make_pair(u,w));
}
void dijkstraShortestPath(int src,vector<pair<int,int> >adj[],int n)
{
    //int i=0,time_=0;
    //making min_heap (by default max heap) pair (distance, vertex)
    //due to this all smallest distance with node comes to top  (Greedy algorithm)
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int>dist(n,INF);
    pq.push(make_pair(0,src));             //add src to priority queue with distance to itself is zero
    dist[src]=0;                            //distance to itself is zero

    while(!pq.empty())
    {
        //extract minimum distance node
        //pop out that node because we then left out with unvisited node with minimum distance
        //thats why we are using priority queue
        int u;
        u=pq.top().second;//second=vertex
        //cout<<pq.top().first<<" "<<u;
        //cout<<"->"<<u;
        pq.pop();
        vector<pair<int,int> >::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();++it)       //go for all adjacent node
        {
            int v= (*it).first;                 //extract its node
            int weight= (*it).second;           //extract its weight (u,v)
            if(dist[u]+weight < dist[v])        //do relaxation
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));      //insert v in p queue even if v already present in p queue
            }
        }

    }
    cout<<"Vertex\t\tDistance from source"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}
int main()
{
    int n,e,a,b,w;
    cout<<"Enter no. of node and edges";
    cin>>n>>e;
    vector<pair<int,int> >adj[n+1];
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b>>w;
        addEdge(adj,a,b,w);
    }
    cout<<"\nEnter vertex no. where you want to find shortest path";
    int t;
    cin>>t;
    dijkstraShortestPath(t,adj,n+1);
}

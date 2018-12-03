#include<bits/stdc++.h>
using namespace std;
vector<int>parent(100);

int find_(int x)            //this function finds the representative of subset
{
    while(parent[x]!=x)
    {
        x=parent[x];
    }
    return x;
}
int union_(int x,int y)
{
    int px=find_(x);        //find representative of x
    int py=find_(y);        //find representative of y
    parent[px]=py;
}
void addEdge(vector<pair<int,pair<int,int> > >edges,int u,int v,int w)
{
    edges.push_back(make_pair(w,make_pair(u,v)));   //edges size is no. of edges
}
void kruskal(vector<pair<int,pair<int,int> > >edges,int n,int e)
{
    //weight ,no. of edges,and keep track of index of edges
    int mst_weight=0,mst_edges=0,mst_i=0;
    sort(edges.begin(),edges.end());    //sort the edges according to its weight
    while(mst_edges<n-1 || mst_i<e)     //up to n-1 edges and also keep track of edges index should not exceed its bound
    {
        int a=edges[mst_i].second.first;
        int b=edges[mst_i].second.second;
        int w=edges[mst_i].first;
        //check a and b both lies on different subset or not if they then combine the subset
        if(find_(a)!=find_(b))
        {
            //combine them
            union_(a,b);
            mst_weight+=w;      //add weight
            mst_edges++;       //increase edges
            cout<<a<<"-"<<b<<" "<<w;
            cout<<endl;  //print edges
        }
        mst_i++;    //increase index

    }
    cout<<"\nWeight of MST is:"<<mst_weight;
}
int main()
{
    for(int i=0;i<100;i++)
        parent[i]=i;
    int n,e;
    int u,v,w;
    cout<<"\nEnter no. of nodes and edges:";
    cin>>n>>e;
    vector<pair<int,pair<int,int> > >edges;  //because we are creating vector not array of vector because input
                                                //would not be in adjacency list
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        addEdge(edges,u,v,w);
    }
    cout<<"Edges in MST are:"<<endl;
    kruskal(edges,n,e);
}

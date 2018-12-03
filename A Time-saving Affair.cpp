#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int u,int v, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
int checkAllow(int k, int time_)
{
    int roundNum=time_;
    if(k==0)
        return roundNum;
    int rem= roundNum%k;
    if(rem==0)
        return roundNum;
    else
        return roundNum-rem;
}
bool checksignal(int k, int time_)
{
    int x=checkAllow(k,time_);
    int que=x/k;
    if(que%2==0)
        return true;
    else
        return false;
}

int leastTimeToInterview(int ne,vector<pair<int,int> >adj[],int src,int k)
{
    //make priority queue (distance,vertex)
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<int>dist(ne,INF);
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {

        //extract minimum time node
        //pop out that node because we then left out with unvisited node with minimum distance
        int u;
        u=pq.top().second;
        int time_=dist[u];  //keep track of time for arriving of each vertex
        //check for signal
        if(u!=ne-1)
        {
            if(!checksignal(k,time_))
                dist[u]=dist[u]+(k-(dist[u]-checkAllow(k,time_)));
        }
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
    return dist[ne-1];

}
int main()
{

    int n,k,m,i,j,t,ne;
    cin>>n;
    cin>>k;
    cin>>m;
    ne=n+1;
    vector<pair<int,int> >adj[ne];
    for(int l=1;l<=m;l++)
    {
        cin>>i>>j>>t;
        //a=i-1;
        //b=j-1;
        if(i!=j)
            addEdge(adj,i,j,t);
    }
    cout<<leastTimeToInterview(ne,adj,1,k);
}

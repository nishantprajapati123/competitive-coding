#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define NINF -INF
using namespace std;
stack<int>extra_node;
int notexist;
int total_node=0;
void addEdges(vector<pair<int,int> >adj[],int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
}
//delete the node
//assign -1 to that node which is pointing to the node which is being deleted
void deleteNode(vector<pair<int,int> >adj[],int x)
{
    while(!adj[x].empty())
    {
        adj[x].pop_back();  //pop out all edges
    }
    vector<pair<int,int> >::iterator i;
   // int cnt=-1;
    for(int j=1;j<=total_node;j++)
    {
   //     cnt=-1;
        for(i=adj[j].begin();i!=adj[j].end();++i)
        {
     //       cnt++;
            if((*i).first==x)   //if node found assign -1
            {
                (*i).first=-1;
            }
        }
    }
}
//calculate farthest distance from x
long int calFarthestNode(int src,vector<pair<int,int> >adj[],int n)
{
    stack<int>extra_node_temp=extra_node;
    int ne=100000;
    //initialize all node to minimum value
    vector<long int>dist(ne,NINF);
    //create max heap (distance,vertex)
    priority_queue<pair<int,int> > maxh;
    dist[src]=0;
    maxh.push(make_pair(0,src));
    while(!maxh.empty())
    {
        int u;
        u=maxh.top().second;
        maxh.pop();
        vector<pair<int,int> >::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();++it)
        {
            int v=(*it).first;
            if(v!=src && v!=-1)
            {
                long int w=(*it).second;
                if(dist[u]+w > dist[v])
                {
                    dist[v]=dist[u]+w;
                    maxh.push(make_pair(dist[v],v));
                }
            }
        }
    }
    total_node=n+extra_node.size();
    /*cout<<"Vertex\t\tDistance from source"<<endl;
    vector<int>::iterator j;
    for(int i=1;i<=total_node;i++)
        cout<<i<<"\t\t"<<dist[i]<<endl;
    cout<<endl<<endl;*/
    long int maxdist=dist[1];        //check for furthest multiple node
    int pos=1;
    for(int i=1;i<=total_node;i++)
    {
        if(dist[i]>maxdist)
        {
            pos=i;
            maxdist=dist[i];
        }
    }
    int removed_node;
    bool found=false;
    while(!extra_node_temp.empty())
    {
        removed_node=extra_node_temp.top();
        extra_node_temp.pop();
        if(removed_node!=notexist)
        {
        if(dist[removed_node]==maxdist)
        {
            found=true;
            break;
        }
        }

    }
    if(found)
        return removed_node; //return recent farthest node
    else
        return pos;      //return farthest node
}
//calculate shortest path
long int shortestPath(vector<pair<int,int> >adj[],int x, int y,int n)
{
    int ne=100000;
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    vector<long int>sdist(ne,INF);
    pq.push(make_pair(0,x));             //add src to priority queue with distance to itself is zero
    sdist[x]=0;                            //distance to itself is zero

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
            int v= (*it).first;//extract its node
            if(v!=x && v!=-1)
            {
                long int weight= (*it).second;           //extract its weight (u,v)
                if(sdist[u]+weight < sdist[v])        //do relaxation
                {
                    sdist[v]=sdist[u]+weight;
                    pq.push(make_pair(sdist[v],v));      //insert v in p queue even if v already present in p queue
                }
            }
        }

    }
    /*cout<<"Vertex\t\tDistance from source"<<endl;
    for(int i=1;i<=total_node;i++)
    {
        cout<<i<<"\t\t"<<sdist[i]<<endl;
    }*/
    return sdist[y]; //return shortest distance from x to y
}
int main()
{
    int n,m,q,x,w;
    cin>>n;
    vector<int>weight(n);
    for(int i=0;i<n;i++)
        cin>>weight[i];
    vector<pair<int,int> >adj[100000];
    for(int i=1;i<=n;i++)
    {
        if(i==n)
            addEdges(adj,n,1,weight[n-1]);
        else
            addEdges(adj,i,i+1,weight[i-1]);
    }
    /*addEdges(adj,4,6,1);
    addEdges(adj,2,7,1);
    addEdges(adj,3,8,1);
    addEdges(adj,5,9,1);
    addEdges(adj,1,10,0);
    extra_node.push(6);
    extra_node.push(7);
    extra_node.push(8);
    extra_node.push(9);
    extra_node.push(10);*/
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>q;
        if(q==1)
        {
            cin>>x>>w;
            int y;  //farthest node from x
            total_node=n+extra_node.size();
            y=calFarthestNode(x,adj,n);
            //join y to new node with weight w
            addEdges(adj,y,total_node+1,w);
            //cout<<"Added node"<<total_node+1;
            //put into stack
            extra_node.push(total_node+1);

        }
        else if(q==2)
        {
            cin>>x>>w;
            total_node=n+extra_node.size();
            //join x to new node of weight w
            addEdges(adj,x,total_node+1,w);
            //cout<<"Added node"<<total_node+1;
            //put in stack
            extra_node.push(total_node+1);
        }
        else if(q==3)
        {
            cin>>x;
            int y;  //farthest node from x
            total_node=n+extra_node.size();
            y=calFarthestNode(x,adj,n);
            //delete y
            //cout<<y;
            notexist=y;
            deleteNode(adj,y);

        }
        else if(q==4)
        {
            cin>>x;
            int y;  //farthest node from x
            total_node=n+extra_node.size();
            y=calFarthestNode(x,adj,n);
            //cout<<y;
            cout<<shortestPath(adj,x,y,n)<<endl;
        }

    }
}

//Directed graph
#include<bits/stdc++.h>
#include<queue>
using namespace std;
void addEdge(vector<int>adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); //adj[v].push_back(u)   for undirected graph
}
void BFS(vector<int>adj[],int u,int n)
{
    int s;
    queue <int> q;
    vector<bool>v(n,false);
    q.push(u);            //push 1st element into queue
    v[u]=true;           //first node visited
    vector<int>::iterator it;
    //till queue not get empty
    while(!q.empty())
    {
        s=q.front();
        //cout<<s<<" ";   //print 1st element
        q.pop();        //remove from beginning
        //get all the adjacent vertex of dequeued element which is not yet visited and marked
        //as visited
        cout<<s<<endl;
        for(it=adj[s].begin();it!=adj[s].end();++it)
        {

            if(!v[*it])
            {
                q.push(*it);
                v[*it]=true;
            }
        }
    }
}
int main()
{
    int n,e;
    int a,b,t;
    cout<<"Enter no. of nodes and edges: ";
    cin>>n>>e;
    vector<int>adj[n];
    cout<<"\nEnter "<<e<<" edges";
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b;
        addEdge(adj,a,b);
    }
    cout<<"\nEnter node where you want to start traversing";
    cin>>t;
    cout<<"BFS is"<<endl;
    BFS(adj,t,n);

}

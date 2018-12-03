#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>add[],int u, int v)
{
    add[u].push_back(v);
    add[v].push_back(u);
}
bool comp(const pair<int,int>&i, const pair<int,int>&j)
{
    return i.first<j.first;
}
/*vector<int> BFS(vector<int>add[],int u,int n)
{
    int s;
    queue <int> q;
    vector<bool>v(n+1,false);
    vector<int>res;
    q.push(u);
    v[u]=true;
    vector<int>::iterator it;
    while(!q.empty())
    {
        s=q.front();
        //cout<<s<<" ";   //print 1st element
        q.pop();        //remove from beginning
        res.push_back(s);
        for(it=add[s].begin();it!=add[s].end();++it)
        {

            if(!v[*it])
            {
                q.push(*it);
                v[*it]=true;
            }
        }
    }
    return res;
}*/
int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<int>add[n+1];
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        addEdge(add,x,y);
    }
    //for storing no. of adjacent
    vector<pair<int,int> >adjacent(n);
    for(int i=0;i<n;i++)
    {
        adjacent[i]=make_pair(add[i+1].size(),i+1);
    }
    //sort according to their adjacent
    sort(adjacent.begin(),adjacent.end(),comp);


     int l=0,h=n-1;
     int res=INT_MIN;
     while(l!=h)
     {
        int u,u_;
        pair<int,int>vfront,vback;
        //select min adjacent as u and maximum as u'
        vfront=adjacent[l];vback=adjacent[h];
        u=vfront.second;u_=vback.second;
        vector<int>adj(n+1);
        for(vector<pair<int,int> >::iterator it=adjacent.begin();it!=adjacent.end();++it)
            adj[it->second]=it->first;

        int cont=0;
        for(int i=1;i<=n;i++)
        {
            if((a*adj[u])<adj[i] && adj[i]<(b*adj[u_]))
                cont++;
        }
        if(cont>res)
            res=cont;
        l++;h--;
    }
    cout<<res;

}

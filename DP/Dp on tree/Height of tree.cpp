#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,a,n) for(int i=a;i<=n;i++)
#define mod 1000000007
#define pb push_back
const int N=3e5;
vi g[N];
int in[N],out[N];
void dfs1(int u, int parent)
{
    //all have height 0 in starting
    in[u]=0;
    for(auto child:g[u])
    {
        if(child==parent)
            continue;
        dfs1(child,u);
        in[u]=max(in[u],1+in[child]);
    }
}
void dfs2(int u, int parent)
{
    int mx1=-1,mx2=-1;
    for(auto child: g[u])
    {
        if(child==parent) continue;
        if(in[child]>=mx1)
            mx2=mx1,mx1=in[child];
        else if(in[child]>mx2)
            mx2=in[child];
    }
    //traverse again to child of u and calculate out[u]
    for(auto child: g[u])
    {
        if(child==parent) continue;
        int use=mx1;
        //if node is itself mx1 then use mx2 because mx2 will be maximum through it sibling except mx1
        if(mx1==in[child])
            use=mx2;
        out[child]=max(1+out[u],2+use);
        dfs2(child,u);
    }
}
int main()
{
    int n;
    cin>>n;
    fo(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    fo1(i,1,n)
        cout<<max(in[i],out[i])<<" ";
}

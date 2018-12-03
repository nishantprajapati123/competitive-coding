#include<bits/stdc++.h>
#define pb(a) push_back(a)
using namespace std;
const int N=3e5;
vector<int>g[N];
int a[N],dp[N];
void dfs(int u, int p)
{
    dp[u]=a[u]; //copy value in dp
    int mx=0;
    //find maximum among all its child node and finally add into dp
    for(auto child:g[u])
    {
        if(child==p)
            continue;
        dfs(child,u);   //call for its each child
        mx=max(mx,dp[child]);
    }
    dp[u]+=mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,k,j,u,v,m;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0);
    cout<<dp[1]<<endl;
}

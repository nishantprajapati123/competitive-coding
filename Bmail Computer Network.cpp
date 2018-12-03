#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int N=3e5;
vector<int>g[N];
bool dp[N];
void dfs1(int u, int par, int n)
{
   // bool k=0;
    for(int child:g[u])
    {
        if(child==par)
            continue;
        if(child==n)
            dp[child]=1;
        else
            dp[child]=0;
        dfs1(child,u,n);
        dp[u]=dp[u]|dp[child];
    }
//    dp[u]=k;
}
int main()
{
    fastIO;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        g[p].pb(i);
        g[i].pb(p);
    }
    dfs1(1,0,n);
   for(int i=1;i<=n;i++)
    {
        if(dp[i]==1)
            cout<<i<<" ";
    }
}


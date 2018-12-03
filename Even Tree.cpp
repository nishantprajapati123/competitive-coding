#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=101;
vector<int>g[N];
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

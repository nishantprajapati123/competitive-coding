#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector < vector<int> > tree;
ll x;
vector<ll>A;
ll dfs(int u, int parent)
{
    ll c=0;
    for(int child:tree[u])
    {
        if(child==parent) continue;
        ll ans = max(-x,dfs(child,u));
        c+=ans;
    }
    return (c+A[u]);
}

void init(int n)
{
    A.clear();
    A.resize(n + 1);
    tree.clear();
    tree.resize(n + 1);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
//        ll x;
        cin>>n>>x;
        init(n);
        for(int i=1;i<=n;i++)   cin>>A[i];
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        cout<< max(-x, dfs(1,0))<<"\n";
    }
    return 0;
}

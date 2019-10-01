#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
const int N = 1e5 + 2;
vector<int>adj[N];
vector<int>A(N);
vector<int>cats(N,0);
int totalVisit(int parent, int u, int m)
{
    int rest = 1;
    int sum = 0;
    for(int child:adj[u])
    {
        if(child == parent)
            continue;
        if(A[child-1] == 1)
            cats[child] = cats[u]+1;
        else
            cats[child] = 0;
        sum += totalVisit(u,child,m);
        rest = sum;
    }
    if(cats[u]<=m)
        return rest;
    else
        return 0;
}
int main()
{
    fastIO
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cats[1] = A[0];
    cout<<totalVisit(-1,1,m);
    return 0;
}


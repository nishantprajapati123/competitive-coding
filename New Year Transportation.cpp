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
const int N = 1e5;
vector<int>adj[N];
vector<int>A(N);
vector<bool>V(N,false);
bool dfs(int x, int t, int* reach)
{
    V[x] = true;
    if(x == t)
        *reach = t;
    for(int child:adj[x])
    {
        if(!V[child])
            dfs(child,t,reach);
    }
}
int main()
{
    fastIO
    int n, t;
    cin>>n>>t;
    for(int i=0;i<n-1;i++)
        cin>>A[i];

    for(int i=1;i<=n-1;i++)
        adj[i].pb(i+A[i-1]);

    int match;
    dfs(1,t,&match);
    if(match == t)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}


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
const int N = 105;
vector<int>adj[N];
vector<bool>V(N,false);
void dfs(int u)
{
    V[u] = true;
    for(int child:adj[u])
    {
        if(!V[child])
            dfs(child);
    }
}
int main()
{
    fastIO
    int n;
    cin>>n;
    vector<pii>cord(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        cord[i] = mk(x,y);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(cord[i-1].first == cord[j-1].first || cord[i-1].second == cord[j-1].second)
            {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    //check how many times dfs execute
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        if(!V[i])
        {
            dfs(i);
            res++;
        }
    }
    cout<<res-1<<"\n";
    return 0;
}


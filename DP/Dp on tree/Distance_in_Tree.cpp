#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mk make_pair
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF (ll)1e30
#define fastIO ios::sync_with_stdio(0); cin.tie(0);

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int N = 50005;
const int K = 505; 
vi g[N];
ll dp[N][K];
int parent[N];

void dfs(int u, int p, int k)
{
    parent[u] = p;
    dp[u][0] = 1;
    for(auto child: g[u])
    {
        if(child == p)  continue;
        dfs(child, u, k);
        
        // dp[u][0] = 0;
        for(int i=1;i<=k;i++)
            dp[u][i] += dp[child][i-1];
    }
}
void solve()
{
    int n, k;
    cin>>n>>k;

    for(int i=1;i<=n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0,k);
    ll ans = 0;

    for(int u=1;u<=n;u++)
    {
        //simple path
        ll a = dp[u][k], b = 0;
        for(int child: g[u])
        {
            if(child == parent[u])  continue;
            for(int x = 1;x<k;x++)
            {
                b += (dp[child][x-1] * (dp[u][k-x] - dp[child][k-x-1]));
            }
        }
        ans += (a + 0.5*b);
    }
    cout<<ans<<"\n";
    
}
int main()
{
    fastIO
    solve();
    return 0;
}
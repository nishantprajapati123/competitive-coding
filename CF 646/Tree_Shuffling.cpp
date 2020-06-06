#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mk 				make_pair
#define ff 				first
#define ss 				second
#define deb(x) 			cout << #x << "=" << x << endl
#define all(x) 			x.begin(), x.end()
#define clr(x) 			memset(x, 0, sizeof(x))
#define sortall(x) 		sort(all(x))
#define PI 				3.1415926535897932384626
#define MOD 			1000000007
#define INF 			(ll)1e30
#define fastIO 			ios::sync_with_stdio(0); cin.tie(0);	cout.tie(0);

typedef pair<int, int> 	pii;
typedef pair<ll, ll> 	pll;
typedef vector<int> 	vi;
typedef vector<ll> 		vl;
typedef vector<pii> 	vpii;
typedef vector<pll> 	vpll;
typedef vector<vi> 		vvi;
typedef vector<vl> 		vvl;
const int N = 200005;
vi g[N];
vi a(N), b(N), c(N), min_a(N);
ll ans = 0;
pair<ll,ll> dfs(int u, int p)
{
    int node_type[2] = {0,0};
    if(b[u] != c[u])
    {
        node_type[b[u]]++;
    } 
    for(auto child: g[u])
    {
        if(child == p)  continue;
        min_a[child] = min(min_a[u], a[child]);
        pair<ll, ll> remain = dfs(child, u);
        node_type[remain.ff] += remain.ss;
    }

    ll x = min(node_type[0], node_type[1]);
    ans +=  (ll)2 * x * min_a[u];
    node_type[0] -= x;
    node_type[1] -= x;

    if(node_type[0] == 0 && node_type[1] == 0)
        return {0,0};
    
    if(node_type[0] > 0)
    {
        if(p == 0)
            ans = -1;
        return {0, node_type[0]};
    }
    if(node_type[1] > 0)
    {
        if(p == 0)
            ans = -1;
        return {1, node_type[1]};
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }

    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    min_a[1] = a[1];
    dfs(1,0);
    cout<<ans<<"\n";
}
int main()
{
    fastIO
    // ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int T;
    // cin>>T;
    // for(int testcase = 1; testcase<=T; testcase++)
    // {
    //     solve();
    // }
    solve();

    return 0;
}
// problem link :- https://codeforces.com/gym/286325/problem/B
// Basically the idea is we have two operations. So, when a[u] == b[u] check for both operations and when a[u] != b[u] check for both
// so either invert a[u] or not invert a[u].

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

const auto start_time = chrono::high_resolution_clock::now();
void nishant_raja();
int pow(int base, int exp);
ll seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
// ============================

const int N = 100005;
vi g[N];
vi a(N), b(N);
int memo[N][2];
//inv = 0, not inverted ..... inv = 1, inverted
int dfs(int u, int p, int inv)
{
    if(memo[u][inv] != -1)  return memo[u][inv];

    int curr_val = a[u] xor inv;    //get current value, if inv = 0 -> get a[u] val.....if inv = 1 -> get inverted of a[u].
    int cost_subtree = 0, cost_simple = 0;

    for(auto child: g[u])
    {
        if(child == p)  continue;

        // Invert entire subtree
        cost_subtree += dfs(child, u, inv xor 1);

        // Invert only current value
        cost_simple += dfs(child, u, inv);
    }

    int res;
    //Not only apply first type, apply second type then apply first type on curr_root
    if(curr_val == b[u])
        res = min(cost_simple, 1 + cost_subtree + 1);
    else
        //either apply first type or second type
        res = min(1 + cost_simple, 1 + cost_subtree);

    memo[u][inv] = res;
    return res;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cin>>b[i];
    memset(memo, -1, sizeof(memo));
    cout<<dfs(1, 0, 0)<<"\n";

}
int main()
{
    fastIO
    // ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    nishant_raja();
    return 0;
}

int pow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) 
    {
        if (exp & 1) result = ((ll)result * base) % MOD;
        base = ((ll)base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
void nishant_raja()
{
    #ifndef ONLINE_JUDGE
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_time-start_time;
        cerr<<"Time Taken : "<<diff.count()<<"\n";
    #endif
}
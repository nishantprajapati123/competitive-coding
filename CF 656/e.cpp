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

void topo(vector<int>g[], int u, vector<bool>&vis, vector<int>&order)
{
    vis[u] = true;
    for(auto child: g[u])
    {
        if(!vis[child]) topo(g, child, vis, order);
    }

    order.pb(u);
}
void solve()
{
    int n, m;
    cin>>n>>m;
    vi g[n+1];

    vpii dir, und;
    for(int i=1;i<=m;i++)
    {
        int t, u, v;
        cin>>t>>u>>v;
        if(t==1)
        {
            g[u].pb(v);
            dir.pb({u, v});
        }
        else
            und.pb({u,v});
    }
    vi order;
    vector<bool>vis(n+1, false);
    bool valid = true;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) topo(g, i, vis, order);
    }
    // for(int i: order)   cout<<i<<" ";
    // cout<<endl;
    if(order.size() < n)
    {
        cout<<"NO\n";
    }
    else
    {
        map<int, int>sq;
        reverse(all(order));
        for(int i=0;i<order.size();i++) sq[order[i]] = i;
        bool ok = true;
        for(int i=1;i<=n;i++)
        {
            for(int j: g[i])
            {
                if(sq[i] > sq[j]) 
                {
                    ok = false;
                    break;
                }
            }
        }

        if(!ok)
        {
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
        for(auto ed: dir)   cout<<ed.ff<<" "<<ed.ss<<"\n";

        for(auto ed: und)
        {
            if(sq[ed.ff] < sq[ed.ss])
                cout<<ed.ff<<" "<<ed.ss<<"\n";
            else
                cout<<ed.ss<<" "<<ed.ff<<"\n";
        }
    }
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
    cin>>T;
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
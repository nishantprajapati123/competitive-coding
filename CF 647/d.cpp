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

int pow(int base, int exp);
// ============================

const int N = 500005;
vi g[N], refer[N], topic(N,0);
void solve()
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        topic[i] = t;
        refer[t].pb(i);
    }

    vi result;
    bool valid = true;

    for(int i=1;i<=n;i++)
    {
        for(int node: refer[i])
        {
            set<int>st;
            for(int neigh: g[node])
            {
                if(topic[neigh] < topic[node])
                    st.insert(topic[neigh]);
                
                if(topic[neigh] == topic[node])
                {
                    valid = false;
                    break;
                }
            }
            if(st.size() != topic[node]-1)
            {
                valid = false;
                break;
            }
            result.pb(node);
        }
    }

    if(!valid)
        cout<<"-1\n";
    else
    {
        for(int x: result)
            cout<<x<<" ";
        cout<<"\n";
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
    // cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}

int mpow(int base, int exp) {
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
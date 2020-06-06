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
const int N = 1005;
vector<int>level(N);
vector<int>nodes_in_level(N);
vi g[N];
void dfs(int u, int p)
{
    for(auto child: g[u])
    {
        if(child == p)  continue;
        level[child] = level[u]  +1;
        dfs(child, u);
    }
}
void solve()
{
    int n, x;
    cin>>n>>x;
    for(int i=0;i<N;i++)
    {
        level[i] = 0;
        nodes_in_level[i] = 0;
    }

    for(auto &x: g)
        x.clear();


    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    level[x] = 0;
    dfs(x,-1);

    int max_level = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        nodes_in_level[level[i]]++;
        if(max_level < level[i])
            max_level = level[i];
    }

    ll sum = 0;
    for(int i=max_level;i>=2;i--)
        sum += nodes_in_level[i];

    int turn;
    if(sum %2 == 0)
        turn = 1;   //Ayush
    else
        turn = 0;   //Ashish

    if(nodes_in_level[1] == 0)
        cout<<"Ayush\n";
    else if(nodes_in_level[1] == 1)
        cout<<"Ayush\n";
    else
    {
        if((nodes_in_level[1] - 1)%2 == 0)
        {
            if(turn == 0)
                cout<<"Ashish\n";
            else
                cout<<"Ayush\n";
        }
        else
        {
            if(turn == 0)
                cout<<"Ayush\n";
            else
                cout<<"Ashish\n";
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

    int T;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}
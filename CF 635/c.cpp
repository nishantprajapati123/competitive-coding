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
const int N = 200005;
vi g[N];
vi level(N), father(N), cnt_sons(N), marked(N);
priority_queue<pair<int, int> >Q;
void dfs(int u, int p)
{
    father[u] = p;
    for(int &child: g[u])
    {
        if(child == p)  continue;
        cnt_sons[u]++;
        level[child] = level[u]+1;
        dfs(child,u);
    }

    //push all leaf node to queue with initial 
    //cost is level of node;
    if(cnt_sons[u] == 0)
        Q.push(mk(level[u], u));
}
void solve()
{
    int n, k;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0,-1);
    ll ans = 0;
    while(k && !Q.empty())
    {
        auto node_pair = Q.top();
        int node_father = father[node_pair.second];
        Q.pop();

        ans += node_pair.first;
        k--;
        marked[node_pair.second]++;

        if(node_father!=-1)
        {
            cnt_sons[node_father]--;
            marked[node_father] += marked[node_pair.second];
            if(cnt_sons[node_father] == 0)
                Q.push({level[node_father] - marked[node_father], node_father});
        }
    }
    cout<<ans<<"\n";


}
int main()
{
    fastIO
    solve();
    return 0;
}
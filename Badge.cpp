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
const int N = 1002;
vector<int>g[N];
vector<bool>vis(N, false);
vi ans;

void dfs(int a, bool &f)
{
    vis[a] = true;
    for(auto child: g[a])
    {
        if(!vis[child])
        {
            dfs(child, f);
            if(f)   return;           
        }
        else
        {
            ans.pb(child);
            f = true;
            return;
        }
        
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        g[i+1].pb(v);
    }
    for(int i=1;i<=n;i++)
    {
        bool f = false;
        for(int i=1;i<=n;i++)   vis[i] = false;
        dfs(i, f);
    }
    for(int x:ans)
        cout<<x<<" ";
}
int main()
{
    fastIO
    solve();
    return 0;
}
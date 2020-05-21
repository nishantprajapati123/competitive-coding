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
const int N = 100005;
vector<int>g[N];
set<bool>s;
//if s,size()==2 that means we have odd length between two leaves else even length 
//for odd length min = 3 for even length min = 1
void dfs(int u, int parent, bool parity)
{
    if(g[u].size() == 1)
        s.insert(parity);
    parity ^= 1;
    for(int child:g[u])
    {
        if(child!=parent)
            dfs(child,u,parity);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].pb(b);g[b].pb(a);
    }
    dfs(1,0,0);

    int mx = n-1;
    for(int u=1;u<=n;u++)
    {
        int cnt = 0;
        for(int v:g[u])
        {
            if(g[v].size() == 1)    cnt ++;
        }
        mx -= max(0, cnt-1);
    }
    cout<<(s.size()==1?"1":"3")<<" "<<mx<<"\n";

}
int main()
{
    fastIO
    solve();
    return 0;
}
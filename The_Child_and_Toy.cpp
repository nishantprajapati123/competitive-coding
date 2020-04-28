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
const int N = 1005;
vector<int>g[N];
vector<pii>v(N);
vector<int>price(N);

void solve()
{
    int n, m;
    cin>>n>>m;

    // priority_queue<pii, vpii, cmp>pq;
    for(int i=1;i<=n;i++)   
    {
        cin>>price[i];
        v[i].first = price[i];
        v[i].second = i;
    }

    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ll ans = 0;

    sort(v.begin()+1, v.begin()+n+1);
    for(int i=n;i>=1;i--)
    {

        price[v[i].second] = 0;
        for(int child: g[v[i].second])
        {
            ans += price[child];
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
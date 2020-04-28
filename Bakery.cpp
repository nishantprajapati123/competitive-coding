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
vector<pair<int, int> >g[N];
set<int>storage;
void solve()
{
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        g[a].pb(mk(b,w));
        g[b].pb(mk(a,w));
    }
    vi A(k);
    for(int i=0;i<k;i++)
    {
        int a;
        cin>>a;
        storage.insert(a);
        A[i] = a;
    }

    ll ans = INF;
    for(int i=0;i<k;i++)
    {
        for(auto child: g[A[i]])
        {
            int v = child.first;
            if(storage.find(v) == storage.end())    ans = min(ans, (ll)child.second);
        }
    }

    cout<<((ans == INF)?-1:ans);

}
int main()
{
    fastIO
    solve();
    return 0;
}
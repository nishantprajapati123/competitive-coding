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
vi parent(N, -1);
vl dist(N, INF);
void print(int n)
{
    if(n == -1) return ;
    print(parent[n]);
    cout<<n<<" ";
}
void solve()
{
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        g[a].pb(mk(b,w));
        g[b].pb(mk(a,w));
    }
    priority_queue<pair<int, int>, vpii, greater<pair<int, int>> >pq;
    dist[1] = 0;
    pq.push(mk(0, 1));

    while(!pq.empty())
    {
        auto a = pq.top(); pq.pop();
        int u = a.second;
        for(auto child: g[u])
        {
            int v = child.first;
            int w = child.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(mk(dist[v], v));
            }
        }
    }

    if(parent[n] == -1) cout<<"-1\n";
    else    print(n);
}
int main()
{
    fastIO
    solve();
    return 0;
}
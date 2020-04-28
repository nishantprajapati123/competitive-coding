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
vector<int>vertex(N, -1);
bool bfs(int u)
{
    vertex[u] = 1;//assign u -> 1
    queue<int>q;
    q.push(u);

    while(!q.empty()){

        int x = q.front();
        q.pop();
        int c = vertex[x];

        for(int child: g[x])
        {
            if(vertex[child] == c)  return false;

            if(vertex[child] == -1)
            {
                vertex[child] = c^1;
                q.push(child);
            }
        }
    }
    return true;
}
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
        if(vertex[i] == -1)
        {
            if(!bfs(i))
            { 
                cout<<"-1\n";
                return ;
            }
        }
    }

                vector<int>a, b;
                for(int i=1;i<=n;i++)
                {
                    if(vertex[i] == 0)
                        a.pb(i);
                    else if(vertex[i] == 1)
                        b.pb(i);
                }

                cout<<a.size()<<"\n";
                for(int &x:a)
                    cout<<x<<" ";
                cout<<"\n";
                cout<<b.size()<<"\n";
                for(int &x: b)
                    cout<<x<<" ";
                cout<<"\n";
            

}
int main()
{
    fastIO
    solve();
    return 0;
}
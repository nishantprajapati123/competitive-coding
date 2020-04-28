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

const int N = 100000;
vector<int>g[N];
vector<int>revG[N];
vector<int>vis(N, false);
stack<int>st;
vector<vector<int> >scc;
//first dfs to store into stack
void dfs_1(int u)
{
    vis[u] = true;

    for(int child: g[u])
    {
        if(!vis[child])
            dfs_1(child);
    }

    //After exploring all children
    //top of stack has element that has finished last
    //bottom of stack has element that has finished first
    st.push(u);

}
void reverseGraph(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int child: g[i])
            revG[child].pb(i);
    }
}

//just for traverse and store answer
void dfs_2(int u, vector<int>&comp)
{
    vis[u] = true;
    comp.pb(u);

    for(int child: revG[u])
    {
        if(!vis[child])
            dfs_2(child, comp);
    }

}

int main()
{
    fastIO
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].pb(v);     //directed
    }

    //call for each vertex
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs_1(i);
    }

    //reverse graph
    // new graph in revG
    reverseGraph(n);

    //reset visited vector
    for(int i=1;i<=n;i++)
        vis[i] = false;

    //pop from stack and do dfs
    while(!st.empty())
    {
        int v = st.top(); st.pop();

        if(!vis[v])
        {
            vector<int>comp;
            dfs_2(v, comp);

            //store answer
            scc.pb(comp);
        }
    }

    //print answer
    for(auto &x: scc)
    {
        for(int &y: x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
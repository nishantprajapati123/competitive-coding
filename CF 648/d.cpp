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
int d1[] = {-1,0,1,0};
int d2[] = {0,1,0,-1};
bool isSafe(int x, int y, int n, int m)
{
    return (x>=0 && x<n && y>=0 && y<m);
}
void dfs(int x, int y, vector<string>&grid, vector<vector<bool> >&vis, int n, int m)
{
    if(grid[x][y] != '#')
        vis[x][y] = true;
    else
        return;

    for(int d=0;d<4;d++)
    {
        int nx = x + d1[d];
        int ny = y + d2[d];
        if(isSafe(nx,ny,n,m) && !vis[nx][ny])
            dfs(nx,ny,grid,vis, n, m);
    }
}
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++)
        cin>>grid[i];
    
    bool valid = true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 'B')
            {
                for(int d=0;d<4;d++)
                {
                    int x = i+d1[d];
                    int y = j+d2[d];
                    if(isSafe(x,y,n,m) && grid[x][y] == '.')
                        grid[x][y] = '#';
                    else if(isSafe(x,y,n,m) && grid[x][y] == 'G')
                        valid = false;
                }
            }
        }
    }
    if(!valid)
    {
        cout<<"No\n";
        return;
    }
    vector<vector<bool> >vis(n, vector<bool>(m, false));
    dfs(n-1, m-1, grid, vis, n, m);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == 'G' && !vis[i][j])
                valid = false;
        }
    }
    if(valid)   cout<<"Yes\n";
    else    cout<<"No\n";
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
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}

int pow(int base, int exp) {
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
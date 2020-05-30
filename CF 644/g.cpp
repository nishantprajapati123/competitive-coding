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
#define fastIO ios::sync_with_stdio(0); cin.tie(0);	cout.tie(0);

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve()
{
    int n, m, a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int> >ans(n, vector<int>(m,0));
    vector<int>col(m,0);
    if(n*a != m*b)
    {
        cout<<"NO\n";
        return ;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a;j++)
            ans[i][(i*a + j)%m] = 1;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<ans[i][j];
        cout<<"\n";
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
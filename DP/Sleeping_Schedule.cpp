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
const int N = 2005;
void solve()
{
    int n, h, l ,r;
    cin>>n>>h>>l>>r;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++)   cin>>a[i];

    vector<vector<int> >dp(N, vector<int>(N));

    dp[0][0] = 0;
    for(int i=1;i<h;i++)
        dp[0][i] = -1;

    for(int i=1;i<=n;i++)
    {
        for(int hr=0;hr<h;hr++)
        {
            dp[i][hr] = -1;
        }

        for(int hr=0;hr<h;hr++)
        {
            if(dp[i-1][hr]==-1) continue;

            int h1 = (hr + a[i]-1)%h;
            int h2 = (hr + a[i])%h;

            dp[i][h1] = max(dp[i][h1], dp[i-1][hr] + (l<=h1 && h1<=r));
            dp[i][h2] = max(dp[i][h2], dp[i-1][hr] + (l<=h2 && h2<=r));
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++)
    {
        if(dp[n][i]!=-1)
            ans = max(ans, dp[n][i]);
    }
    cout<<ans<<"\n";
}
int main()
{
    fastIO
    solve();
    return 0;
}
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
void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int>a(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(n > m)
    {
        cout<<"YES\n";
        return ;
    }

    vector<vector<bool> >dp(N, vector<bool>(N, false));

    for(int i=1;i<=n;i++)
    {
        for(int rem=0; rem<m; rem++)
        {
            if(dp[i-1][rem])
            {
                int rem_after_add = (rem + a[i])%m;
                dp[i][rem_after_add] = true;

                dp[i][rem] = true;
            }
        }
        dp[i][a[i]%m] = true;
    }

    if(dp[n][0])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    fastIO
    solve();
    return 0;
}
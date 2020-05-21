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
#define MOD 998244353
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
#define Nmax 1000005
void fix(int &x) {
    if(x >= MOD) {
        x -= MOD;
    }
}
void solve()
{
    char s[Nmax], t[Nmax];
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    // cout<<n<<endl;
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for(int i = m; i <= n; i++) {
        if(i > m || s[i] == t[m]) {
            dp[i][0] = 1;
        }
        if(s[i] == t[1]) {
            dp[i][1] = 1;
        }
    }
    
    for(int i = n; i > 1; i--) {
        for(int j = 0; j <= n - i + 1; j++) {
            // i - 1 -> 0
            if(j + 1 > m || s[i - 1] == t[j + 1]) {
                //cout << i << " " << j << "\n";
                dp[i - 1][j + 1] += dp[i][j];
                fix(dp[i - 1][j + 1]);
            }
            if(i > 1) {
                // i - 1 -> 1
                int x = j + i - 1; //ones
                if(x > m || s[i - 1] == t[x]) {
                    dp[i - 1][j] += dp[i][j];
                    fix(dp[i - 1][j]);
                }
            }
        }
    }
    for(int j = 0; j <= n; j++) {
        ans += dp[1][j];
        fix(ans);
    }
    cout << ans << "\n";    


}
int main()
{
    fastIO
    solve();
    return 0;
}
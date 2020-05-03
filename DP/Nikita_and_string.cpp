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
void solve()
{
    string s;
    getline(cin, s);

    int n = s.length();
    // string a, a, b,  ab, ba, aba
    int dp[3][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[0][i] = dp[0][i-1] + (s[i-1] == 'a');  //max count of a
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + (s[i-1] == 'b');  //max count  of a or ab or b
        dp[2][i] = max(dp[1][i-1], dp[2][i-1]) + (s[i-1] == 'a');   //max count of a or ab or b or ba or aba
    }
    cout<<max({dp[0][n],dp[1][n], dp[2][n]})<<"\n";
}
int main()
{
    fastIO
    solve();
    return 0;
}
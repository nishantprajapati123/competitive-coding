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
    ll x,y,a,b;
    cin>>x>>y;
    cin>>a>>b;

    ll mn = min(x,y);
    ll mx = max(x,y);

    ll ans = 0;
    if(2*a < b)
    {
        ans += 2*a*mn;
        ans += (mx-mn)*a;
    }
    else
    {
        ans += mn*b;
        ans += (mx-mn)*a;
    }
    cout<<ans<<"\n";
}
int main()
{
    fastIO
    int T;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();

    }
    return 0;
}
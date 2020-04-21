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
const int N = 400005;
vi b(N);
map<int, ll>mp;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)    cin>>b[i];

    ll ans = INT_MIN;
    for(int i=1;i<=n;i++)
    {
        // if(b[i] - i < 0)    continue;
        mp[b[i] - i] += b[i];
    }

    for(auto it: mp)
        ans = max(ans, it.second);

    cout<<ans<<"\n";

}
int main()
{
    fastIO
    solve();
    return 0;
}
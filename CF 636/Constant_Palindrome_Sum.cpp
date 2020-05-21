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
    ll n, k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    vector<pair<int, int> >input;

    for(int i=0;i<n/2;i++)
    {
        int mn = min(a[i], a[n-i-1]);
        int mx = max(a[i], a[n-i-1]);
        input.pb(mk(mn,mx));
    }

    vector<ll>pref(2*k+2, 0);
    map<int, int>cnt;
    for(auto &x: input)
    {
        cnt[x.first+x.second]++;    // no. of pair required 0 changes
        int l = x.first + 1;
        int r = x.second + k;
        pref[l]++;
        pref[r+1]--;
    }

    for(int i=2;i<=2*k;i++)
        pref[i] += pref[i-1];

    ll min_change = n;
    for(int i=2;i<=2*k;i++)
    {
        ll cnt0 = cnt[i];
        ll cnt1 = pref[i] - cnt0;
        ll cnt2 = (n/2) - cnt1 - cnt0;

        ll t_changes = 0*cnt0 + 1*cnt1 + 2*cnt2;
        min_change = min(min_change, t_changes);
    }
    cout<<min_change;

}
int main()
{
    fastIO
    int T;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
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
// 1
// 4
// 6 8
// 9 3
// 8 1
// 9 7
void solve()
{
    int n;
    cin>>n;
    vl a(n), b(n);

    for(int i=0;i<n;i++)    cin>>a[i]>>b[i];

    //double array
    a.resize(2*n);
    b.resize(2*n);
    for(int i=0;i<n;i++)
    {
        a[i+n] = a[i];
        b[i+n] = b[i];
    }

    vector<ll>cost(2*n);
    for(int i=1;i<2*n;i++)
        cost[i] = max((ll)0, a[i] - b[i-1]);

    ll ans = INF;
    ll sum = 0;
    int i;
    for(i=1;i<n;i++)
        sum += cost[i];

    int j = 0;

    ans = min(ans,a[0]+sum);
    // cout<<j<<" "<<sum<<" "<<i<<"\n";
    while(1)
    {
        j++;
        sum = sum - cost[j] + cost[i];
        // cout<<j<<" "<<sum<<" "<<i<<"\n";
        ans = min(ans, a[j]+sum);
        i++;
        if(i == 2*n)    break;
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
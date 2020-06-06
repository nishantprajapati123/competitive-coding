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
    ll n, x;
    cin>>n>>x;
    vl a(2*n+1,0), pre_hugg(2*n+1,0), pre_day(2*n+1,0);
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n] = a[i];
    }
    for(ll i=1;i<=2*n;i++)
    {
        pre_hugg[i] = pre_hugg[i-1] + ((a[i]*(a[i]+1))/2);
        pre_day[i] = pre_day[i-1] + a[i];
    }

    ll ans = 0;
    for(ll i=2*n;i>=n+1;i--)
    {
        ll l=1, h=i, rem = i;
        while(l<=h)
        {
            ll mid = (l+h)/2;
            if(pre_day[i] - pre_day[mid] < x)
            {
                rem = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
            
        } 
        ll extra_day = pre_day[i] - pre_day[rem-1] - x;
        ll hugg = pre_hugg[i] - pre_hugg[rem-1];
        hugg = hugg - ((extra_day*(extra_day+1))/2);
        // cout<<extra_day<<endl;
        ans = max(ans, hugg);
        // cout<<"ok\n";
    }
    cout<<ans<<"\n";
}
int main()
{
    fastIO
    // ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int T;
    // cin>>T;
    // for(int testcase = 1; testcase<=T; testcase++)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
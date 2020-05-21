#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
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
    ll n;
    cin>>n;

    if(n == 1)
    {
        cout<<"0\n";
        return;
    }
    ll ans = 0;
    ll diog = n / 2;
    // deb(diog);
    ans += 4*((diog*(diog + 1))/2);
    // deb(ans);
    ll count_ex_diog_center = n - 3;
    // deb(count_ex_diog_center);
    ll one_side = count_ex_diog_center/2;
    // deb(one_side);

    ll sum = 0;
    for(ll i=1;i<=one_side;i++)
    {
        sum += (i*(i+1))/2;
    }
    // deb(sum);
    ans += 8*sum;
    // deb(ans);
    // ll t = 4*pow(diog,2);
    ll t = 0;
    for(ll i=1;i<=diog;i++)
    {
        t += pow(i,2);
    }
    // deb(t);
    ans += 4*t;

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

    int T;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}
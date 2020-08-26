#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mk 				make_pair
#define ff 				first
#define ss 				second
#define deb(x) 			cout << #x << "=" << x << endl
#define all(x) 			x.begin(), x.end()
#define clr(x) 			memset(x, 0, sizeof(x))
#define sortall(x) 		sort(all(x))
#define PI 				3.1415926535897932384626
#define MOD 			1000000007
#define INF 			(ll)1e30
#define fastIO 			ios::sync_with_stdio(0); cin.tie(0);	cout.tie(0);

typedef pair<int, int> 	pii;
typedef pair<ll, ll> 	pll;
typedef vector<int> 	vi;
typedef vector<ll> 		vl;
typedef vector<pii> 	vpii;
typedef vector<pll> 	vpll;
typedef vector<vi> 		vvi;
typedef vector<vl> 		vvl;

int pow(int base, int exp);
// ============================

void solve()
{
    int n, x;
    cin>>n>>x;
    vi a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    vl pref(n+1,0);
    ll sum = 0;
    unordered_map<ll, ll>mp;
    ll ans = INT_MIN;
    int not_div = -1;
    int div = -1;
    // for(int i=0;i<n;i++)
    //     pref[i+1] = pref[i] + a[i];

    // int l = 0, h = n;
    // for(int i=0;i<n;i++)
    // {
    //     if((pref[n]-pref[i])%x != 0)
    //     {
    //         cout<<n-i<<"\n";
    //         return;
    //     }
    // }
    // cout<<"-1\n";
    for(ll i=0;i<n;i++)
    {
        sum += a[i];
        if(sum %x != 0) ans = max(ans, i+1);

        if((sum%x != 0) && not_div == -1)
            not_div = i;
        
        else if((sum%x == 0) && div == -1)
            div = i;

        else if(sum%x == 0 && not_div != -1)
            ans = max(ans, i - not_div);
        else if(sum%x != 0 && div != -1)
            ans = max(ans, i - div);
    }
    if(ans == INT_MIN)
        cout<<"-1\n";
    else
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

    int T = 1;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}

int pow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) 
    {
        if (exp & 1) result = ((ll)result * base) % MOD;
        base = ((ll)base * base) % MOD;
        exp >>= 1;
    }
    return result;
}
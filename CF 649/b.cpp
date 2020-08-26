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
    int n;
    cin>>n;
    vi p(n);
    for(int i=0;i<n;i++)    cin>>p[i];
    vi dec(n,0), inc(n,0);
    vi ans;
    int both = 0;

    for(int i=1;i<n-1;i++)
    {
        if(p[i] < p[i+1] && p[i] < p[i-1])
            dec[i] = 1;
        if(p[i] > p[i+1] && p[i] > p[i-1])
            inc[i] = 1;
    }
    for(int i=0;i<n;i++)
    {
        if(i == 0 || i == n-1)
            ans.pb(p[i]);
        else if(dec[i] || inc[i])
            ans.pb(p[i]);
    }

    cout<<ans.size()<<"\n";
    for(int &x: ans)
        cout<<x<<" ";
    cout<<"\n";
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
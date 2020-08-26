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
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    int one = 0;
    ll ans = 0;
    for(auto &x: s)
    {
        if(x == '1') one++;
    }

    if(one == 0)
    {
        for(int i=0;i<n;i = i+k+1)
        {
            ans++;
        }
        cout<<ans<<"\n";
        return;
    }
    vi a(n,0), b(n,0);
    int i=0;
    a[0] = k+1;
    while(i<n)
    {
        if(s[i] == '1')
            a[i] = k+1;
        else if(i == 0)
        {
            i++;
            continue;
        }
        else
        {
            a[i] = a[i-1] - 1;
        }
        
        if(a[i] == 0)   a[i] = k+1;
        i++;
    }
    i = n-1;
    while(a[i] != k+1)  
    {
        i--;
    }
    int invalid = 0;
    b[i] = k+1;
    i--;
    while(i >= 0)
    {

        if(a[i] == k+1 && b[i+1] != 1)
        {
            b[i] = k+1;
            invalid++;
        }
        else if(i == n-1)
        {
            i--;
            continue;
        }
        else
        {
            b[i] = b[i+1] - 1;
        }
        
        if(b[i] == 0)   b[i] = k+1;
        i--;
    }
    // for(int x: a)   cout<<x<<" ";
    // cout<<endl;
    // for(int x: b)   cout<<x<<" ";
    // cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(a[i] == k+1 && b[i]==k+1 && s[i] == '0')   ans++;
    }
    // cout<<ans<<" "<<invalid<<endl;
    cout<<ans-invalid<<"\n";
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
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

const auto start_time = chrono::high_resolution_clock::now();
void nishant_raja();
int pow(int base, int exp);
ll seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
// ============================

bool check(int a, int b, int c, int x, int y, int z)
{
    return (x == max(a,b)) && (y == max(a,c)) && (z == max(b,c));
}
void solve()
{
    int x, y, z;
    cin>>x>>y>>z;

    int a, b, c;
    if(x == y && y == z)
    {
        cout<<"YES\n";
        cout<<x<<" "<<y<<" "<<z<<"\n";
        return;
    }
    
    if(x == y)
    {
        a = x, b = z, c = 1;
        if(check(a,b,c,x,y,z))
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
        a=x, c = z, b = 1;
        if(check(a,b,c,x,y,z))
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
    }
    if(y == z)
    {
        a = x, c = y, b=1;
        if(check(a,b,c,x,y,z))
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
        b=x, c=y, a=1;
        if(check(a,b,c,x,y,z))
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
    }
    if(x == z)
    {
        b=x, a=y, c=1;
        if(check(a,b,c,x,y,z))
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
        b=x, c=y,a=1;
        if(check(a,b,c,x,y,z))
        {
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
    }

    a = x, c = y, b = z;
    if(check(a,b,c,x,y,z))
    {
        cout<<"YES\n";
        cout<<a<<" "<<b<<" "<<c<<"\n";
        return;
    }
    b = x, a = y, c = z;
    if(check(a,b,c,x,y,z))
    {
        cout<<"YES\n";
        cout<<a<<" "<<b<<" "<<c<<"\n";
        return;
    }
    cout<<"NO\n";
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
    nishant_raja();
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
void nishant_raja()
{
    #ifndef ONLINE_JUDGE
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end_time-start_time;
        cerr<<"Time Taken : "<<diff.count()<<"\n";
    #endif
}
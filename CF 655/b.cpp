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
// bool checkPrime(ll n)
// {
//     int count = 0;
//     for(ll i=1;i*i<=n;i++)
//     {
//         if(n%i == 0)
//         {
//             if(i*i == n)
//                 count++;
//             else
//                 count += 2;
//         }
//     }
//     return count == 2;
// }
vector<ll> factor(ll n)
{
    vector<ll>ans;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            if(i*i == n)
                ans.push_back(i);
            else
            {
                ans.pb(i);
                ans.pb(n/i);
            }
            
        }
    }
    sortall(ans);
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    // cout<<n<<"-> ";
    if(n%2 == 0)
    {
        cout<<n/2<<" "<<n/2<<"\n";
        return;
    }
    // cout<<"ok"<<endl;
    vector<ll>fact = factor(n);
    if(fact.size() == 2)
    {
        cout<<fact[0]<<" "<<(fact[1]-1)<<"\n";
    }
    else
    {
        ll m = fact.size();
        for(int i=m-2;i>=0;i--)
        {
            ll a = fact[i];
            ll b = n - a;
            if(b%a == 0)
            {
                cout<<a<<" "<<b<<"\n";
                return;
            }
        }
    }
    // for(auto x: fact)   cout<<x<<" ";
    // cout<<endl;
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
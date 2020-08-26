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
string str = "abacaba";
int valid(string &s)
{
    int cnt = 0;
    for(int i=0;i<=s.length()-7;i++)
    {
        if(s.substr(i,7) == str)    cnt++;
    }
    return cnt;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool ans = false;
    for(int i=0;i<=n-7;i++)
    {
        string ss = s;
        bool ok = true;
        for(int j=0;j<7;j++)
        {
            if(ss[i + j] != '?' && ss[i + j] != str[j])
            {
                ok = false;
                break;
            }
            ss[i + j] = str[j];
        }
        if(ok && valid(ss) == 1)
        {
            for(int j=0;j<n;j++)
            {
                if(ss[j] == '?')    ss[j] = 'z';
            }
            ans = true;
            cout<<"Yes\n";
            cout<<ss<<"\n";
            break;
        }
    }
    if(!ans)
    {
        cout<<"No\n";
    }
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
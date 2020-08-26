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

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    unordered_map<ll,ll>freq;
    // unordered_set<int>unique;

    // priority_queue<pair<int, int> >pq;
    ll total = 0;
    int g4 = 0, g2 = 0;
    for(int i=0;i<n;i++)    
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    vector<pair<int, int> >cnt(100005, {0,0});
    for(auto it: freq)
    {
        g4 = 0, g2 = 0;
        if(it.ss >= 4)
        {
            g4 = it.ss/4;
            g2 = (it.ss - ((it.ss/4)*4))/2;
        }
        else
        {
            g2 = it.ss/2;
        }
        cnt[it.ff] = {g4, g2};
    }
    int tg4 = 0,tg2 = 0;
    for(int i=0;i<100005;i++)
    {
        tg4 += cnt[i].ff;
        tg2 += cnt[i].ss;
    }

    int q;
    cin>>q;
    while(q--)
    {
        char c;
        int x, t=3;
        bool found = false;
        cin>>c>>x;
        if(c == '+')
        {
            freq[x]++;
        }
        else
        {
            freq[x]--;
        }
            tg4 -= cnt[x].ff;
            tg2 -= cnt[x].ss;

            cnt[x].ff = freq[x]/4;
            cnt[x].ss = (freq[x] - (cnt[x].ff*4))/2;
            tg4 += cnt[x].ff;
            tg2 += cnt[x].ss;
            // deb(tg4);deb(tg2);
            if(tg4>=2 || (tg4>=1 && tg2>=2))
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
            
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
    // cin>>T;
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
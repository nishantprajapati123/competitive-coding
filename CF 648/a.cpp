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
    int n, m;
    cin>>n>>m;
    // vector<vector<int> >mat(n, vector<int>(m));
    vector<bool>rows(n, false);
    vector<bool>cols(m, false);
    int x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            if(x == 1)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }  
    }

    int flag = 0;   //Ashish turn, flag = 1 Vivek
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!rows[i] && !cols[j])
            {
                rows[i] = true;
                cols[j] = true;
                flag ^= 1;
            }
        }
    }
    if(flag == 1)
        cout<<"Ashish\n";
    else
        cout<<"Vivek\n";


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
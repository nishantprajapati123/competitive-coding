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

void solve()
{
    ll a, b;
    cin>>a>>b;
    if(a == b)
    {
        cout<<"0\n";
        return;
    }
    ll ans;
    ll max_a = max(a,b);
    ll min_b = min(a,b);

    if(max_a % min_b != 0)
    {
        cout<<"-1\n";
        return ;
    }
    ll q = max_a / min_b;
    ll cnt = 0;
    while(q!=1)
    {
        if(q%8 == 0)
        {
            q = q/8;
            // cout<<"8\n";
        }
        else if(q%4 == 0)
        {
            q = q/4;
            // cout<<"4\n";
        }
        else if(q%2 == 0)
        {
            q = q/2;
            // cout<<"2\n";
        }
        else
        {
            cout<<"-1\n";
            return;
        }
        cnt++;
    }
    cout<<cnt<<"\n";
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
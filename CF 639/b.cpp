#include<bits/stdc++.h>
using namespace std;

#define ll long long int
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
const int N = 100001;
vector<ll>cardReq(N);
void solve()
{
    ll n;
    cin>>n;
    
    // auto id = lower_bound(cardReq.begin(), cardReq.end(), n) - cardReq.begin();
    // cout<<id<<" "<<cardReq[id]<<endl;
    ll ans = 0;
    while(n > 0)
    {
        ll mx_h_id = lower_bound(cardReq.begin(), cardReq.end(), n) - cardReq.begin();
        // deb(mx_h_id);
        // deb(n);
        if(cardReq[mx_h_id] == n)
        {
            ans ++;
            n = n - cardReq[mx_h_id];
        }
        else
        {
            mx_h_id--;
            if(mx_h_id<=0)  break;
            ans++;
            n = n - cardReq[mx_h_id];
        }
        
    }
    cout<<ans<<"\n";

    // for(int i=1;i<=10;i++)  cout<<cardReq[i]<<endl;

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

    //precompute
    cardReq[0] = 0;
    cardReq[1] = 2;
    for(int h=2;h<=N;h++)
    {
        cardReq[h] = cardReq[h-1] + (h-1) + (h*2);
    }
        
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}
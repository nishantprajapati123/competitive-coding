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
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    ll mx;
    ll prev_sum = 0, sum = 0;    
    bool neg = a[0]>0?true:false;
    int i=0;
    for(;i<n;)
    {
        mx = -INF;
        if(neg)
        {
            while(i<n && a[i] > 0)
            {   
                mx = max(a[i], mx);
                i++;
            }
            neg = false;
        }
        else
        {
            while(i<n && a[i] < 0)
            {
                mx = max(a[i], mx);
                i++;
            }
            neg = true;
        }
        
        sum += mx;
    }
    cout<<sum<<"\n";
    
}
int main()
{
    fastIO
    int T;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}
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

    if((n/2)&1)
    {
        cout<<"NO";
        return ;
    }

    vector<int>ans(n);
    ll sum1 = 0;
    for(int i=0;i<n/2;i++)
    {
        ans[i] = (i+1)*2;
        sum1 += ans[i];
    }
    ll sum2 = 0;
    for(int i = n/2;i<n-1;i++)
    {
        ans[i] = ans[i - n/2] - 1;
        sum2 += ans[i];
    }
    ans[n-1] = sum1 - sum2;
    cout<<"YES\n";
    for(int &x: ans)    cout<<x<<" ";
}
int main()
{
    fastIO
    int T;
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
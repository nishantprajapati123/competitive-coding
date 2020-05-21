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
    int n, k;
    cin>>n>>k;
    vector<int>a(n);
    set<int>uq;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        uq.insert(a[i]);
    }
    if(uq.size() > k)
    {
        cout<<"-1\n";
        return ;
    }
    int p=1;
    while(uq.size()!=k)
    {
        uq.insert(p++);
    }
    // int total_sum = accumulate(a.begin(), a.end(), 0);
    bool valid = true;
    bool same = true;
    for(int i=0;i<n-1;i++)
    {
        if(a[i] != a[i+1])
        {
            same = false;
            break;
        }
    }
    if(same)
    {
        cout<<n<<"\n";
        for(int &x: a)
            cout<<x<<" ";
        cout<<"\n";
        return;
    }
    
    int sz = 0;
    vector<int>ans;
    while(sz < n*n)
    {
        for(int x: uq)
            ans.pb(x);
        sz += uq.size();
    }

    cout<<n*n<<"\n";
    for(int i=0;i<n*n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";

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
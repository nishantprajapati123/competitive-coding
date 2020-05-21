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
    vi a(n);
    for(int i=0;i<n;i++)    cin>>a[i];
    if(n < 2)
    {
        cout<<"0";
        return ;
    }
    set<int>dis;
    map<int, ll>rep;
    for(int x:a)    dis.insert(x);
    for(int x:a)    rep[x]++;
    ll mx = INT_MIN;
    for(auto it: rep)   mx = max(mx, it.second);

    ll gp1 = dis.size();
    gp1--;
    cout<<max(min(gp1, mx), min(gp1+1, mx-1));

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
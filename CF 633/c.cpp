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

    int mx = a[0];
    int diff = 0;
    for(int i=0;i<n;i++)
    {
        diff = max(diff, mx - a[i]);
        mx = max(mx, a[i]);
        // deb(i);deb(mx);deb(diff);
    }

    int count = 0;
    //raise that diff to become equal to larger value
    //we have only one way to do i.e., add 2^t-1 add select any indices.
    while (diff)
    {
        count++;
        diff = diff>>1;
    }
    cout<<count;
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
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
    vector<int>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];

    sortall(a);
    int x = (n&1)?n/2: n/2 - 1;

    cout<<a[x]<<" ";
    for(int i=x+1;i<n;i++)
    {
        if(i == n-1 && !(n&1))
            cout<<a[i]<<" ";
        else if(i == n-1 && (n&1))
            cout<<a[n-1]<<" "<<a[0]<<" ";
        else
            cout<<a[i]<<" "<<((n&1)?a[n-1-i]:a[n-2-i])<<" ";
    }
    

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
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
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int N = 100001;

void solve()
{
    int n;
    cin>>n;
    vl A(n);
    for(int i=0;i<n;i++)    cin>>A[i];

    ll left  = 0, right = 0, cnt = 0;
    ll i = 1;
    while(i<=n)
    {
        // deb(i);
        if(!(A[i-1]%2))
        {
            left = right;
            right = i;
        }
        if(!(A[i-1]%4))
        {
            left = i;
            right = i;
        }
        cnt += i-right+left;

        i++;
    }
    cout<<cnt;
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
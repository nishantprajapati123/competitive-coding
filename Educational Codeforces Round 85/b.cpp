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
int solve()
{
    int n, x;
    cin>>n>>x;

    vector<int>A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];

    // sort()
    // ll sum = accumulate(A.begin(),A.end(),0);
    sort(A.begin(),A.end());
    ll sum = 0;
    int i;
    for(i=n-1;i>=0;i--)
    {
        sum += A[i];
        if((double)sum/(n-i) < x)
            break;
    }
    return (n-1-i);

}
int main()
{
    fastIO
    int T;
    // scanf("%d", &T);
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        int ans = solve();
        cout<<ans<<"\n";
    }
    return 0;
}
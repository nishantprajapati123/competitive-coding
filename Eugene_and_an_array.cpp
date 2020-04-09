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

int A[200002];
void solve()
{
    int n;
    scanf("%d", &n);

    ll sum = 0;
    int mx = 0;
    map<ll,int>mp;
    ll ans = 0;
    mp[0] = -1;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        sum += A[i];
        if(mp.find(sum)!=mp.end())
        {
            if(sum == 0 && mp[0] == -1)
                mx = max(mx,1);
            else
                mx = max(mx,mp[sum]+1);
        }
        mp[sum] = i;
        ans += i - mx;

    }
    printf("%lld\n",ans);
}
int main()
{
    fastIO
    solve();
    return 0;
}
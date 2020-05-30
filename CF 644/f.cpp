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
bool different(string &x, string &y)
{
    int cnt = 0;
    for(int i=0;i<x.length();i++)
    {
        if(x[i] != y[i])
            cnt++;
    }
    return cnt<=1;
}
void solve()
{
    int n, m;
    cin>>n>>m;
    cin.ignore();
    vector<string>a(n);

    for(int i=0;i<n;i++)    cin>>a[i];

    int count = 0;

    string ans = "";
    for(int pos=0;pos<m;pos++)
    {
        ans = a[0];
        for(char c='a';c<='z';c++)
        {
            ans[pos] = c;
            count = 0;
            for(int i=0;i<n;i++)
            {
                if(different(ans, a[i]))
                    count++;
            }
            if(count == n)
            {
                cout<<ans<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
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
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}
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

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)    cin>>a[i];

    sortall(a);
    int sum = accumulate(all(a), 0);

    if(sum %2 == 0)
    {
        cout<<"YES\n";
        return;
    }

    vi odd, even;
    for(int x: a)
    {
        if(x&1)
            odd.pb(x);
        else
            even.pb(x);
    }
    bool ok = false;
    // for(int i=0;i<even.size();i++)
    // {
    //     if(abs(even[i] - odd[0]) == 1)
    //     {
    //         ok = true;
    //         break;
    //     }
    // }
    // if(ok)
    // {
    //     cout<<"YES\n";
    //     return;
    // }
    // for(int i=0;i<even.size();i++)
    // {
    //     if(abs(even[i] - odd[odd.size()-1]) == 1)
    //     {
    //         ok = true;
    //         break;
    //     }
    // }
    // if(ok)
    // {
    //     cout<<"YES\n";
    //     return;
    // }
    // for(int i=0;i<odd.size();i++)
    // {
    //     if(abs(even[0] - odd[i]) == 1)
    //     {
    //         ok = true;
    //         break;
    //     }
    // }
    // if(ok)
    // {
    //     cout<<"YES\n";
    //     return;
    // }
    // for(int i=0;i<odd.size();i++)
    // {
    //     if(abs(even[even.size()-1] - odd[i]) == 1)
    //     {
    //         ok = true;
    //         break;
    //     }
    // }
    // if(ok)
    // {
    //     cout<<"YES\n";
    //     return;
    // }

    // cout<<"NO\n";
    for(int i=0;i<even.size();i++)
    {
        for(int j=0;j<odd.size();j++)
        {
            if(abs(even[i] - odd[j]) == 1)
            {
                ok = true;
                break;
            }
        }
    }
    if(ok)  cout<<"YES\n";
    else    cout<<"NO\n";
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
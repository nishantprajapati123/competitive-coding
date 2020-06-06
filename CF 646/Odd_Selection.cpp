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
    int n, x;
    cin>>n>>x;
    int odd = 0, even = 0;
    vi a(n);
    for(int &x: a)
    {
        cin>>x;
        if(x&1) odd++;
        else    even++;
    }

    if(odd == 0)
    {
        cout<<"NO\n";
        return;
    }

    odd--, x--;
    int odd_pair = odd/2;
    int x_pair = x/2;

    if(odd_pair >= x_pair)
    {
        x -= (x_pair * 2);
        if(x == 0)
        {
            cout<<"YES\n";
            return;
        }
        if(even >= 1)
        {
            cout<<"YES\n";
            return;
        }
        else
        {
            cout<<"NO\n";
            return;
        }
    }
    else
    {
        int rem = x - (odd_pair * 2);
        if(even >= rem)
        {
            cout<<"YES\n";
            return;
        }
        else
        {
            cout<<"NO\n";
            return;
        }
        
    }
    cout<<"NO\n";



    // if(odd >= x && (!(x&1) || )
    // {
    //     cout<<"YES\n";
    //     return ;
    // }

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
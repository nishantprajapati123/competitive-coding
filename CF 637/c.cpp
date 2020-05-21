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
    vi p(n+1);
    map<int, int>pos;
    bool valid = true;
    for(int i=1;i<=n;i++)
    {    
        cin>>p[i];
        pos[p[i]] = i;
    }
    vector<bool>occupy(n+1, false);
    for(int no =1; no<=n;no++)
    {
        occupy[pos[no]] = true;
        if(pos[no]+1 > n)   continue;
        if(!occupy[pos[no]+1] && p[pos[no]+1] != no+1)
        {
            valid = false;
            break;
        }
    }
    if(valid)   cout<<"YES";
    else    cout<<"NO";
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
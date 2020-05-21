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
    string t,s="";
    getline(cin, t);

    bool z = false, o = false;
    for(auto &x: t)
    {    
        if(x == '0')
            z = true;
        else
            o = true;
    }
    if((!z && o) || (z && !o))
    {
        cout<<t<<"\n";
        return;
    }
    int tot = 2*t.length();
    for(int i=0;i<tot;i++)
    {
        if(i&1)
            s += '0';
        else
            s += '1';
    }
    cout<<s<<"\n";

}
int main()
{
    fastIO
    int T;
    cin>>T;
    cin.ignore();
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
    }
    return 0;
}
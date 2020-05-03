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
const int N = 300005;
void solve()
{
    string s="";
    getline(cin, s);
    ll ans = 0;

    for(char &c: s)
    {
        if((c-'0') % 4 == 0)
            ans ++;
    }
    for(int i=0;i<s.length()-1;i++)
    {
        int a = s[i]-'0';
        int b = s[i+1]-'0';
        int c = a*10 + b;
        if(c % 4 == 0)
            ans += (i+1);
    }
    // printf("ok");
    printf("%lld\n", ans);

}
int main()
{
    fastIO
    solve();
    return 0;
}
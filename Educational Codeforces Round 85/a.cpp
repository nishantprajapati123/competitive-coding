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
string solve()
{
    int n;
    cin>>n;
    vector<pair<int,int> >stat(n);

    bool valid = true;
    for(int i=0;i<n;i++)
    {
        cin>>stat[i].first>>stat[i].second;
    }
    // int till_play = 0, till_clear = 0;
    if(stat[0].first < stat[0].second)
        return "NO";
    for(int i=1;i<n;i++)
    {
        if(stat[i].first < stat[i].second)  return "NO";
        if(stat[i].first == stat[i-1].first && stat[i].second != stat[i-1].second)  return "NO";
        if(stat[i].first < stat[i-1].first) return "NO";
        if(stat[i].first > stat[i-1].first && stat[i].second < stat[i-1].second)    return "NO";
        if(stat[i].first - stat[i-1].first < stat[i].second - stat[i-1].second) return "NO";
    }

    return "YES";

}
int main()
{
    fastIO
    int T;
    // scanf("%d", &T);
    cin>>T;
    for(int testcase = 1; testcase<=T; testcase++)
    {
        string ans = solve();
        cout<<ans<<"\n";
        // printf("\n");
    }
    return 0;
}
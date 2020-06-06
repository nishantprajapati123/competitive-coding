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
bool check(string &s)
{
    int i, j;
    for(i=0;i<s.length()-1;i++)
    {
        if(s[i] != s[i+1])
            break;
    }
    for(j=s.length()-1;j>0;j--)
    {
        if(s[j] != s[j-1])
            break;
    }
    // cout<<i<<" "<<j<<endl;
    return ((i+1 == j) || (i==s.length()-1 && j == 0));
}
void solve()
{
    string s;
    cin>>s;
    
    if(check(s))
    {
        cout<<"0\n";
        return;
    }

    int zero_count = 0;
    int one_count = 0;
    for(auto x: s)
    {
        if(x == '1')
            one_count++;
        else
            zero_count++;
    }

    vpll zero_pair(s.length(), {0,0}), one_pair(s.length(), {0,0});
    int pref_zero = 0, pref_one = 0;

    for(int i=0;i<s.length();i++)
    {
        zero_pair[i].first = pref_zero;
        zero_pair[i].second = s[i] == '0'?zero_count-pref_zero-1 : zero_count - pref_zero;
        pref_zero = s[i] == '0'?pref_zero + 1: pref_zero;

        one_pair[i].first = i - zero_pair[i].first;
        one_pair[i].second = s.length() - i - 1 - zero_pair[i].second;

    }

    // for(int i=0;i<s.length();i++)
    //     cout<<i+1<<" "<<zero_pair[i].first<<" "<<zero_pair[i].second<<"\t"<<one_pair[i].first<<" "<<one_pair[i].second<<endl;
    ll ans = min(zero_count, one_count);
    for(int i=0;i<s.length();i++)
    {
        ans = min(ans, min(zero_pair[i].first+one_pair[i].second , one_pair[i].first+zero_pair[i].second));
    }
    cout<<ans<<"\n";
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
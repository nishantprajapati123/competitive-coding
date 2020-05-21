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
class cmp
{
public:
bool operator()(const pair<ll, pair<ll,ll> >& p1, const pair<ll, pair<ll,ll> >& p2) 
    {
        if(p1.first == p2.first)
            return p1.second.first > p2.second.first;
        return p1.first < p2.first;
    }
};
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    priority_queue<pair<ll, pair<ll,ll> >, vector<pair<ll, pair<ll,ll> > >, cmp>pq;

    ll l = 1, r = n;
    // deb(l),deb(r);
    ll mid = (l+r)/2;
    a[mid] = 1;
    pq.push(mk(mid-l, mk(l,mid-1)));
    pq.push(mk(r-mid, mk(mid+1, r)));

    int i = 2;
    while(!pq.empty())
    {
        auto sub = pq.top();pq.pop();
        l = sub.second.first;
        r = sub.second.second;
        // deb(l),deb(r);
        // cout<<sub.first<<" "<<l<<" "<<r<<endl;
        if(l <= r)
        {
            mid = (l+r)/2;
            a[mid] = i;
            i++;

            pq.push(mk(mid-l, mk(l,mid-1)));
            pq.push(mk(r-mid, mk(mid+1, r)));
        }
    }

    for(int i=1;i<=n;i++)   cout<<a[i]<<" ";
    cout<<"\n";
    
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
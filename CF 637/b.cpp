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
// const int N = 2000005;
void solve()
{
    int n, k;
    cin>>n>>k;
    vi a(n);
    vector<bool>mark(n, false);
    int min_l, max_p;
    int count = 0;
    int l = 0, r = k-1;

    for(int i=0;i<n;i++)
    {   
        // if() 
        cin>>a[i];
    }

    // queue<int>q;
    
    for(int i=1;i<k-1;i++)
    {
        if(a[i] > a[i-1] && a[i] > a[i+1])
        {    
            mark[i] = true;
            count++;
        }
    }
    min_l = l+1, max_p = count;
    // cout<<l<<" "<<r<<" "<<count<<endl;
    while(r < n-1)
    {
        // deb(l);deb(r);
        
        if(a[r] > a[r-1] && a[r] > a[r+1])
        {   
            mark[r] = true; 
            count++;
        }
        r++;
        l++;
        if(mark[l])
            count--;
            
        
        if(count > max_p)
        {
            max_p = count;
            min_l = l+1;
        }
        // cout<<l<<" "<<r<<" "<<count<<endl;
    }
    // cout<<l<<" "<<r<<" "<<count<<endl;
    cout<<max_p+1<<" "<<min_l;

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
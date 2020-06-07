#include<bits/stdc++.h>
using namespace std;

#define ll 				long long int
#define pb 				push_back
#define mk 				make_pair
#define ff 				first
#define ss 				second
#define deb(x) 			cout << #x << "=" << x << endl
#define all(x) 			x.begin(), x.end()
#define clr(x) 			memset(x, 0, sizeof(x))
#define sortall(x) 		sort(all(x))
#define PI 				3.1415926535897932384626
#define MOD 			1000000007
#define INF 			(ll)1e30
#define fastIO 			ios::sync_with_stdio(0); cin.tie(0);	cout.tie(0);

typedef pair<int, int> 	pii;
typedef pair<ll, ll> 	pll;
typedef vector<int> 	vi;
typedef vector<ll> 		vl;
typedef vector<pii> 	vpii;
typedef vector<pll> 	vpll;
typedef vector<vi> 		vvi;
typedef vector<vl> 		vvl;

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)    cin>>a[i];

    unordered_map<int,int>mp;
    for(auto x: a)
        mp.insert({x,1});
    
    int num = 1;
    int count_size = 0;
    while(num <= 1025)
    {
        unordered_map<int,int>temp = mp;
        count_size = 0;
        for(int x: a)
        {
            if(temp.find(num^x) != temp.end())
            {
                count_size++;
                // cout<<(num^x)<<" ";
                temp.erase(num^x);
            }
            else
                break;
            // for(auto y: temp) cout<<y.ff<<" ";
            // cout<<endl;
        }
        if(count_size == n)
        {
            // cout<<"ok\n";
            cout<<num<<"\n";
            return;
        }
        num++;
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
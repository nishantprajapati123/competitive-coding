#include<bits/stdc++.h>
using namespace std;

#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")

#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"

#define pow2(x) ((x)*(x))
#define ll long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front

#define mod 1000000007
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)

#define mp make_pair
#define ff first
#define ss second
#define null NULL

#define all(c) (c).begin(),(c).end()
#define nl "\n"

typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll,ll> pll;
typedef map< ll,ll> mll;

#define INF 1e9

vector<vector<ll> > g;

void bfs(ll s,vector<ll> &d){
    d[s] = 0;
    queue<ll> q;
    q.push(s);

    while(!q.empty()){
        ll node = q.front();
        q.pop();
        
        for(auto child : g[node]){
            if(d[child]==INF){
                d[child] = d[node] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;


    while(t--){
        
        ll n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;

        --a,--b,--c;

        vector<ll> p(m); // vector of prices
        for(ll i=0;i<m;i++){
            cin>>p[i];
        }

        sort(p.begin(),p.end());

        vector<ll> pref(m+1,0);
        for(ll i=0;i<m;i++){
            pref[i+1] = pref[i] + p[i];
        }

        g = vector<vector<ll>>(n);
        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            --x,--y;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<ll> da(n,INF), db(n,INF), dc(n,INF);
        bfs(a,da);
        bfs(b,db);
        bfs(c,dc);

        ll ans = LLONG_MAX;
        for(ll i=0;i<n;i++){
            if(da[i]+db[i]+dc[i]<=m){
                ans = min(ans , pref[db[i]] + pref[da[i]
                + db[i] + dc[i]]);
            }
        }

             cout<<ans<<"\n";

    }

    
    return 0;
}
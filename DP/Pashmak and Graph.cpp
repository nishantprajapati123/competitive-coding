#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
int main()
{
    fastIO
//    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    int u,v,w;
    vector<pair<int, pair<int,int > > >st;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        st.pb(mk(w,mk(u,v)));
    }
    sort(st.begin(),st.end());
    vector<int>dp(n+1,0);
    int ans = 0;
    vector<pii>p;
    for(int i=0;i<m;i++)
    {
        w = st[i].first;
        u = st[i].second.first;
        v = st[i].second.second;
        int tmp = max(dp[v],dp[u]+1);
        p.pb(mk(v,tmp));
        if(i==m-1 || w!=st[i+1].first)
        {
            while(!p.empty())
            {
                pii curr = p.back();
                p.pop_back();
                dp[curr.first] = max(dp[curr.first],tmp);
            }
        }
    }
    for(int x:dp)
        ans = max(ans,x);
    cout<<ans<<"\n";
    return 0;
}

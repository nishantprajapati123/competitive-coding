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
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>A(n);
        for(int i=0;i<n;i++)    cin>>A[i];
        unordered_map<int,vector<int>>mp;
        ll preXor = 0;
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            preXor ^= A[i];
            if(preXor==0)   ans+=i; //from starting
            if(mp.find(preXor)!=mp.end())
            {
                for(auto itr=mp[preXor].begin();itr!=mp[preXor].end();++itr)
                    ans += (i-(*itr))-1;
            }
            mp[preXor].pb(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}


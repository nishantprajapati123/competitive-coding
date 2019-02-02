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
    int t;
    cin >> t;
    while(t--)
    {
        int N,K;
        cin>>N>>K;
        vector<int>price(K);
        for(int i=0;i<K;i++)
            cin>>price[i];
        ll dp[K+1];
        dp[0]=0;
        for(int j=1;j<=K;j++)
        {
            ll res=INT_MAX;
            for(int i=1;i<=j;i++)
            {
                if(price[i-1]!=-1)
                    res = min(res,dp[j-i]+price[i-1]);
            }
            dp[j] = res;
        }
        cout<<(dp[K]==INT_MAX?-1:dp[K])<<"\n";
    }
    return 0;
}

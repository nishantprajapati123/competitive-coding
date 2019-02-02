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
map<ll,ll>dp;
ll recur(ll n)
{
    if(n==0) return 0;
    if(dp[n]!=0) return dp[n];
    ll temp = recur(n/2)+recur(n/3)+recur(n/4);
    dp[n] = max(n,temp);
    return dp[n];
}
int main()
{
    fastIO
    ll n;
    cin>>n;
//    ll dp[n+1];
//    dp[0]=0;
//    memset(dp,0,sizeof(dp));
    cout<<recur(n)<<"\n";

    return 0;
}


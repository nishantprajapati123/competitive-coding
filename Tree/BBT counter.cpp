#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long int BBT(int h)
{
    long long dp[h+1];
    //base case
    dp[0]=dp[1]=1;
    //bottom up
    for(int i=2;i<=h;i++)
    {
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod;
    }
        //dp[i]=(dp[h-1]*((2*dp[h-2])%MOD + dp[h-1])%MOD)%MOD;
    return dp[h];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h;
        cin>>h;
        cout<<BBT(h)<<endl;
    }
}

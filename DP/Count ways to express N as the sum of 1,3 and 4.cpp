i#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int countWays(int dp[], int n)
{
    //base case
    if(n<0)
        return 0;
    if(n==1|| n==0|| n==2)
        return 1;
    if(n==3)
        return 2;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]= ((countWays(dp,n-1)%MOD)+ (countWays(dp,n-3)%MOD) + (countWays(dp,n-4)%MOD))%MOD;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
        cin>>n;
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        cout<<countWays(dp,n)<<endl;
    }
}

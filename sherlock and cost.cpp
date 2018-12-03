#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int dp[100000][2];
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+abs(b[i-1]-1));
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+abs(b[i]-1));
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    }
}

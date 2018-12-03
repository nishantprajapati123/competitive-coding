#include<bits/stdc++.h>
using namespace std;
int vessel(vector<int>arr,int max_, int k)
{
    sort(arr.begin(),arr.end());
    int dp[max_+1][k+1];
    memset(dp,0,sizeof(dp));
    //bottom up
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<=k+1;i++)
        {
            //base condition
            if(i==0 && j==0)
                dp[i][j]=1;
            else
            {
                if(arr[i]>j)    //vessel is greater than that vessel
                    dp[arr[i]][j]=dp[arr[i]-1][j];  //copy previous value
                else
                    dp[arr[i]][j]=dp[arr[i]-1][j] + //exclude
                                  dp[arr[i]][j-arr[i]];
            }
        }

    }
    if(dp[max_][k])
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int max_=arr[0];
        for(int i=0;i<n;i++)
        {
            if(arr[i]<max_)
                max_=arr[i];
        }
        cout<<vessel(arr,max_,k);
    }
}

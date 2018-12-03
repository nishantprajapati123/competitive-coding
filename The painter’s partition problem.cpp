#include<bits/stdc++.h>
using namespace std;
int sum(int arr[], int l , int h)
{
    int s=0;
    for(int i=l;i<=h;i++)
        s+=arr[i];
    return s;
}
int partitionMin(int arr[], int n, int k)
{
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    //base case
    //k=1
    for(int i=1;i<=n;i++)
        dp[1][i]=sum(arr,0,i-1);
    //n=1
    for(int i=1;i<=k;i++)
        dp[i][1]=arr[0];

    for(int i=2;i<=k;i++)
    {
        for(int j=2;j<=n;j++)
        {
            int best= INT_MAX;
            for(int p=1;p<=j;p++)
                best=min(best,max(dp[i-1][p],sum(arr,p,j-1)));
            dp[i][j]=best;
        }
    }
    return dp[k][n];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<partitionMin(arr,n,k)<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
long getWays(vector<long>c,long n,int m)
{
    int Max=INT_MIN;
    //find maximum coin type
    for(int i=0;i<m;i++)
    {
        if(c[i]>Max)
            Max=c[i];
    }
    long dp[Max+1][n+1];
    sort(c.begin(),c.end());
    //base condition
    dp[0][0]=1;
    int i,j;
    for(j=1;j<n+1;j++)
        dp[0][j]=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(c[i]>j && (i-1)>=0)
                dp[c[i]][j]=dp[c[i-1]][j];
            else if(c[i]>j && (i-1)<0)
                dp[c[i]][j]=dp[0][j];   //copy form 0th row and same column
            else if(c[i]<=j && (i-1)>=0)
                dp[c[i]][j]=dp[c[i-1]][j]+ //exclude
                            dp[c[i]][j-c[i]];
            else if(c[i]<=j && (i-1)<0)
                dp[c[i]][j]=dp[0][j]+ //exclude
                            dp[c[i]][j-c[i]];

        }
    }
    return dp[Max][n];
}
int main()
{
    long n;
    int m;
    cin>>n>>m;
    vector<long>c(m);
    for(int i=0;i<m;i++)
        cin>>c[i];
    cout<<getWays(c,n,m);
}

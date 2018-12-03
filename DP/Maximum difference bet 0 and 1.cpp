#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s="";
        getline(cin,s);
        long int n=s.length();
        int dp[n];
        memset(dp,0,sizeof(dp));
        //base condition
        if(s[0]=='1')
            dp[0]=-1;
        else
            dp[0]=1;
            //bottom up
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1')
                dp[i]=max(dp[i]-1,dp[i-1]-1);   //not include start with single 1 (0-1) and include with previous
            else
                dp[i]=max(dp[i]+1,dp[i-1]+1); //start new window and include with previous
        }
        int m=dp[0];
        for(int i=0;i<n;i++){
            if(dp[i]>m)
                m=dp[i];
        }
        cout<<m<<endl;
    }
}

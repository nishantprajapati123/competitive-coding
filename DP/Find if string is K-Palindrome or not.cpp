#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cin.ignore();
        string s1="",s2="";
        getline(cin,s1);
        s2=s1;
        reverse(s2.begin(),s2.end());   //reverse string
        int len=s1.length();
        int dp[n+1][n+1];   //storing previous state
        //(a)if 1st string is empty remove element of 2nd string
        //(b)if 2nd is empty remove element of 1st string
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                //(b)
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)  //(a)
                    dp[i][j]=i;
                else if(s1[i]==s2[j])
                    dp[i][j]=dp[i-1][j-1];  //just ignore copy the previous value
                else
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
       /* if(dp[n][n]<=2*k)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl; */
        cout<<dp[n][n];
    }
}

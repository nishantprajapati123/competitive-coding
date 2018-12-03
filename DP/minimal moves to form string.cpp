#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        int n=s.length();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=INT_MAX;
        dp[0]=1; //adding 1st element;
        string s1="",s2="";
        s1+=s[0];
        for(int i=1;i<n;i++)
        {
            s1+=s[i];
            //for appending
            s2=s.substr(i+1,i+1);
            //add
            dp[i]=min(dp[i],dp[i-1]+1);
            if(s1==s2)
                dp[i*2+1]=min(dp[i]+1,dp[i*2+1]);

        }
        cout<<dp[n-1]<<endl;
    }
}

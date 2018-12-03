#include<bits/stdc++.h>
using namespace std;
int calLSC(string s1, string s2,int n, int m)
{
    int a[n+1][m+1];
    //bottom up approach
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;  //because not selecting any one of string
            else if(s1[i-1]==s2[j-1])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]= max(a[i-1][j],a[i][j-1]);
        }
    }
    int le=a[n][m];
    return (n+m-le);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1="",s2="";
        cin>>s1>>s2;
        int n=s1.length(),m=s2.length();
        cout<<calLSC(s1,s2,n,m)<<endl;
    }
}
